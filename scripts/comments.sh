#!/bin/bash
set -e

AUTHOR="Hao Chen"
LEETCODE_URL=https://oj.leetcode.com/problems/

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
    xidel_tar=xidel-0.8.4.linux64.tar.gz
    if [ ! -f ${xidel_tar} ]; then
        echo "Downloading xidel....."
        curl -L http://softlayer-sng.dl.sourceforge.net/project/videlibri/Xidel/Xidel%200.8.4/${xidel_tar} -o ${xidel_tar}
    fi
    tar -zxvf ${xidel_tar}
    ./install.sh
    cd ..
    echo "Install xidel successfullly !"
}

if [ $# -lt 1 ] || [[ "${1}" != ${LEETCODE_URL}* ]]; then
    usage
    exit 255
fi


leetcode_url=$1
current_time=`date +%Y-%m-%d`

if [ $# -gt 1 ] && [ -f $2 ]; then
    source_file=$2
    current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
else
    source_file=${1#${LEETCODE_URL}}
    source_file=${source_file::${#source_file}-1}
    source_file=`echo $source_file | awk -F '-' '{for (i=1; i<=NF; i++) printf("%s", toupper(substr($i,1,1)) substr($i,2)) }'`.cpp

    if [ ! -f ${source_file} ]; then
        echo "Create a new file - ${source_file}."
        echo -e "\n" > ${source_file}
        current_time=`date +%Y-%m-%d`
    else
        current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
    fi
fi

#adding the Copyright Comments
if  ! grep -Fq "// Author :" $source_file ; then
    sed -i '1i\'"// Source : ${leetcode_url}" $source_file
    sed -i '2i\'"// Author : ${AUTHOR}" $source_file
    sed -i '3i\'"// Date   : ${current_time}\n" $source_file
fi

#grab the problem description and add the comments
xidel=`type -P xidel || /bin/true`
if [ -z "${xidel}" ]; then
    echo "xidel not found !"
    install_xidel
fi

xidel ${leetcode_url} -q -e "css('div.question-content')"  | \
    grep -v '                ' |sed '/^$/N;/^\n$/D'  | \
    sed 's/^/ * /' | sed "1i/*$(printf '%.0s*' {0..80}) \n * " | \
    sed "\$a \ $(printf '%.0s*' {0..80})*/\n" > /tmp/tmp.txt

sed -i '4 r /tmp/tmp.txt' ${source_file}

rm -f /tmp/tmp.txt

echo "${source_file} updated !"

