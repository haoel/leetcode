#!/bin/bash
set -e

AUTHOR="Hao Chen"
LEETCODE_URL=https://leetcode.com/problems/
LEETCODE_NEW_URL=https://leetcode.com/problems/
LEETCODE_OLD_URL=https://oj.leetcode.com/problems/
COMMENT_TAG="//"
FILE_EXT=".cpp"

function usage()
{

    echo -e "Usage: ${0} [url] [source_file]"
    echo -e ""
    echo -e "Example:"
    echo -e ""
    echo -e "   1) Create a file named largestNumber.cpp, and add Copyright & Problem description"
    echo -e "   ${0} https://oj.leetcode.com/problems/largest-number/"
    echo -e ""
    echo -e "   2) Add Copyright & Problem description into existed file"
    echo -e "   ${0} https://oj.leetcode.com/problems/largest-number/ largestNumber.cpp"
    echo -e ""
}

function install_xidel()
{
    echo "Install xidel ..."
    if [ ! -d ./xidel ]; then
        mkdir xidel
    fi
    cd xidel
    linux=`uname -m`
    xidel_tar=xidel-0.8.4.linux64.tar.gz
    case $linux in
        x86_64 )    xidel_tar=xidel-0.8.4.linux64.tar.gz
                    ;;
          i686 )    xidel_tar=xidel-0.8.4.linux32.tar.gz
                    ;;
             * )    echo "Cannot install xidel, please install it manually!"
                    exit 1;
    esac
    if [ ! -f ${xidel_tar} ]; then
        echo "Downloading xidel....."
        curl -L http://softlayer-sng.dl.sourceforge.net/project/videlibri/Xidel/Xidel%200.8.4/${xidel_tar} -o ${xidel_tar}
    fi
    tar -zxvf ${xidel_tar}
    ./install.sh
    cd ..
    echo "Install xidel successfullly !"
}

if [ $# -lt 1 ] || [[ "${1}" != ${LEETCODE_NEW_URL}* ]] && [[ "${1}" != ${LEETCODE_OLD_URL}* ]]; then
    usage
    exit 255
fi

if [[ "${1}" == ${LEETCODE_OLD_URL}* ]]; then
    LEETCODE_URL=${LEETCODE_OLD_URL}
fi

IS_SHELL=`curl ${1} 2>/dev/null | grep Bash |wc -l`
if [ ${IS_SHELL} -gt 0 ]; then
    COMMENT_TAG='#'
    FILE_EXT='.sh'
fi


leetcode_url=$1
current_time=`date +%Y-%m-%d`

if [ $# -gt 1 ] && [ -f $2 ]; then
    source_file=$2
    current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
else
    source_file=${1#${LEETCODE_URL}}
    source_file=${source_file::${#source_file}-1}
    source_file=`echo $source_file | awk -F '-' '{for (i=1; i<=NF; i++) printf("%s", toupper(substr($i,1,1)) substr($i,2)) }'`${FILE_EXT}

    if [ ! -f ${source_file} ]; then
        echo "Create a new file - ${source_file}."
        echo -e "\n" > ${source_file}
        current_time=`date +%Y-%m-%d`
    else
        current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
    fi
fi

# the source file is existed but it is empty, add a line, 
# otherwise it could casue the comments inserts failed.
if [ ! -s $source_file ]; then
    echo "" > $source_file 
fi

#adding the Copyright Comments
if  ! grep -Fq  "${COMMENT_TAG} Author :" $source_file ; then
    sed -i '1i\'"${COMMENT_TAG} Source : ${leetcode_url}" $source_file
    sed -i '2i\'"${COMMENT_TAG} Author : ${AUTHOR}" $source_file
    sed -i '3i\'"${COMMENT_TAG} Date   : ${current_time}\n" $source_file
fi

#grab the problem description and add the comments
xidel=`type -P xidel || /bin/true`
if [ -z "${xidel}" ]; then
    echo "xidel not found !"
    install_xidel
fi

# using xidel grab the problem description
# 1) the `fold` command is used to wrap the text at centain column
# 2) the last two `sed` commands are used to add the comments tags
case $FILE_EXT in
    .cpp )      xidel ${leetcode_url} -q -e "css('div.question-content')"  | \
                    grep -v '                ' |sed '/^$/N;/^\n$/D'  | fold -w 85 -s |\
                    sed 's/^/ * /' | sed "1i/*$(printf '%.0s*' {0..80}) \n * " | \
                    sed "\$a \ $(printf '%.0s*' {0..80})*/\n" > /tmp/tmp.txt
                ;;
    .sh )      xidel ${leetcode_url} -q -e "css('div.question-content')"  | \
                    grep -v '                ' |sed '/^$/N;/^\n$/D'  | fold -w 85 -s| \
                    sed 's/^/# /' | sed "1i#$(printf '%.0s#' {0..80}) \n# " | \
                    sed "\$a \#$(printf '%.0s#' {0..80})\n" > /tmp/tmp.txt
                ;;
      * )       echo "Bad file extension!"
                exit 1;

esac

#insert the problem description into the source file, and remove it
sed -i '4 r /tmp/tmp.txt' ${source_file}
rm -f /tmp/tmp.txt

echo "${source_file} updated !"

