#!/bin/bash
set -e

pushd `dirname $0` > /dev/null
SCRIPTPATH=`pwd -P`
popd > /dev/null
SCRIPTFILE=`basename $0`

COLOR_INFO='\033[0;36m'
COLOR_NONE='\033[0m'

source ${SCRIPTPATH}/lib/query_problem.sh

function usage()
{

    echo -e "Usage: ${0} [url]"
    echo -e ""
    echo -e "Example:"
    echo -e ""
    echo -e "   Create a directory named as largestNumber, and create the source file inside"
    echo -e "   ${0} https://leetcode.com/problems/largest-number/"
    echo -e ""
}

if [ $# -lt 1 ] || [[ "${1}" != ${LEETCODE_NEW_URL}* ]] && [[ "${1}" != ${LEETCODE_OLD_URL}* ]]; then
    usage
    exit 255
fi

if [[ "${1}" == ${LEETCODE_OLD_URL}* ]]; then
    LEETCODE_URL=${LEETCODE_OLD_URL}
fi


leetcode_url=$1

get_question_slug ${leetcode_url}

dir_name=`echo ${QUESTION_TITLE_SLUG} | awk -F '-' '{for (i=1; i<=NF; i++) printf("%s", toupper(substr($i,1,1)) substr($i,2)) }'`

dir_name=`echo ${dir_name:0:1} | tr '[A-Z]' '[a-z]'`${dir_name:1}

mkdir -p ${dir_name}
cd ${dir_name}

file=`${SCRIPTPATH}/comments.sh ${leetcode_url} | grep updated | awk '{print $1}'`

git add ${file}
vi "${file}"


