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
    echo -e "   ${0} https://leetcode.com/problems/largest-number/"
    echo -e ""
    echo -e "   2) Add Copyright & Problem description into existed file"
    echo -e "   ${0} https://leetcode.com/problems/largest-number/ largestNumber.cpp"
    echo -e ""
}

function detect_os()
{
    platform='unknown'
    ostype=`uname`
    if [[ "$ostype" == 'Linux' ]]; then
       platform='linux'
    elif [[ "$ostype" == 'Darwin' ]]; then
       platform='macos'
    fi
    echo ${platform}
}

function install_xidel()
{
    echo "Install xidel ..."
    if [ ! -d ./xidel ]; then
        mkdir xidel
    fi
    cd xidel

    platform=`detect_os`

    if [[ "$platform" == "unknown" ]]; then
        echo "Unknown platform, please install 'xidel' manually!"
        exit 1;
    fi

    #install the xidel on Linux platform
    if [[ "$platform" == "linux" ]]; then
        hardware=`uname -m`
        xidel_tar=xidel-0.8.4.linux64.tar.gz
        case $hardware in
            x86_64 )    xidel_tar=xidel-0.8.4.linux64.tar.gz
                        ;;
              i686 )    xidel_tar=xidel-0.8.4.linux32.tar.gz
                        ;;
                 * )    echo "Cannot install xidel, please install it manually!"
                        exit 1;
        esac
        if [ ! -f ${xidel_tar} ]; then
            echo "Downloading xidel......"
            curl -L http://softlayer-sng.dl.sourceforge.net/project/videlibri/Xidel/Xidel%200.8.4/${xidel_tar} -o ${xidel_tar}
        fi
        tar -zxvf ${xidel_tar}
        ./install.sh
    fi

    #install the xidel on MacOS platform
    #refer to: https://www.evernote.com/shard/s69/sh/ff1e78f3-a369-4855-b18f-6184ce789c45/f3511927d0fb356ce883835f2eb712e0
    if [[ "$platform" == "macos" ]]; then
        echo "Downloading xidel......" 
        xidel_zip=xidel.zip
        if [ ! -f ${xidel_zip} ]; then
            curl -L https://www.evernote.com/shard/s69/sh/ff1e78f3-a369-4855-b18f-6184ce789c45/f3511927d0fb356ce883835f2eb712e0/res/9f156868-01b4-4838-9c2f-935d7a236e05/${xidel_zip} -o ${xidel_zip}
        fi 
        unzip ${xidel_zip}
        mv xidel /usr/local/bin/
    fi

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
platform=`detect_os`

if [ $# -gt 1 ] && [ -f $2 ]; then
    source_file=$2
    if [[ "$platform" == "linux" ]]; then
        current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
    elif [[ "$platform" == "macos" ]]; then
        current_time=`stat -f %a ${source_file} | xargs -I time date -r time +%Y-%m-%d`
    fi
else
    source_file=${1#${LEETCODE_URL}}
    source_file=${source_file::${#source_file}-1}
    source_file=`echo $source_file | awk -F '-' '{for (i=1; i<=NF; i++) printf("%s", toupper(substr($i,1,1)) substr($i,2)) }'`${FILE_EXT}

    if [ ! -f ${source_file} ]; then
        echo "Create a new file - ${source_file}."
        echo -e "\n" > ${source_file}
        current_time=`date +%Y-%m-%d`
    else
        if [[ "$platform" == "linux" ]]; then
            current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
        elif [[ "$platform" == "macos" ]]; then
            current_time=`stat -f %a ${source_file} | xargs -I time date -r time +%Y-%m-%d`
        fi
    fi
fi

# the source file is existed but it is empty, add a line, 
# otherwise it could casue the comments inserts failed.
if [ ! -s $source_file ]; then
    echo "" > $source_file 
fi

#adding the Copyright Comments
if  ! grep -Fq  "${COMMENT_TAG} Author :" $source_file ; then
    sed -i.bak '1i\'$'\n'"${COMMENT_TAG} Source : ${leetcode_url}"$'\n' $source_file
    sed -i.bak '2i\'$'\n'"${COMMENT_TAG} Author : ${AUTHOR}"$'\n' $source_file
    sed -i.bak '3i\'$'\n'"${COMMENT_TAG} Date   : ${current_time}"$'\n' $source_file
    sed -i.bak '4i\'$'\n'""$'\n' $source_file
    rm ${source_file}.bak
fi

#grab the problem description and add the comments
TRUE_CMD=`which true`
xidel=`type -P xidel || ${TRUE_CMD}`
if [ -z "${xidel}" ]; then
    echo "xidel not found !"
    install_xidel
fi

# using xidel grab the problem description
# 1) the `fold` command is used to wrap the text at centain column
# 2) the last two `sed` commands are used to add the comments tags
case $FILE_EXT in
    .cpp )      xidel ${leetcode_url} -q -e "css('div.question-content')"  | \
                    grep -v '             ' | sed '/^$/N;/^\n$/D'  | fold -w 85 -s |\
                    sed 's/^/ * /' | sed '1i\'$'\n'"/*$(printf '%.0s*' {0..85}) "$'\n' |\
                    sed '2i\'$'\n''!@#$%'$'\n' | sed 's/!@#$%/ */' | \
                    sed '$a\'$'\n'"*$(printf '%.0s*' {0..85})*/"$'\n'| \
                    sed 's/^*/ /' > /tmp/tmp.txt
                ;;
    .sh )      xidel ${leetcode_url} -q -e "css('div.question-content')"  | \
                    grep -v '             ' |sed '/^$/N;/^\n$/D'  | fold -w 85 -s| \
                    sed 's/^/# /' | sed '1i\'$'\n'"#$(printf '%.0s#' {0..85}) "$'\n' | \
                    sed '2i\'$'\n''#'$'\n' | sed '$a\'$'\n'"#$(printf '%.0s#' {0..85})"$'\n'\
                    > /tmp/tmp.txt
                ;;
      * )       echo "Bad file extension!"
                exit 1;

esac

#insert the problem description into the source file, and remove it
sed -i.bak '4 r /tmp/tmp.txt' ${source_file}
rm -f ${source_file}.bak
rm -f /tmp/tmp.txt

echo "${source_file} updated !"

