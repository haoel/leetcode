#!/bin/bash


function usage()
{

    echo -e "Usage: ${0} [file]"
    echo -e ""
    echo -e "Example:"
    echo -e ""
    echo -e "   ${0} ./LargestNumber.cpp"
    echo -e ""
}



if [ $# -lt 1 ] || [[ ! -f ${1} ]]; then
    usage
    exit 255
fi

DIR=`cd $(dirname ${1}) && pwd -P`
FILE=${DIR}/$(basename ${1})

URL=`grep Source ${FILE} | awk '{print $4}'`
title_str=`xidel ${URL} -q -e "css('div.question-title h3')"` 
NUM=`echo ${title_str} | awk -F '.' '{print $1}'`
TITLE=`echo ${title_str} | awk -F '.' '{print $2}' | sed -e 's/^[[:space:]]*//'`
DIFFCULT=`xidel ${URL} -q -e "css('.question-info')" | grep Difficulty | awk '{print $2}'`

FILE=`echo ${FILE} | sed "s/.*\/algorithms/\.\/algorithms/"`

echo "|${NUM}|[${TITLE}](${URL}) | [C++](${FILE})|${DIFFCULT}|"
