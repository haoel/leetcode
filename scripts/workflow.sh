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
    echo -e "   Running workflow for a problem"
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

platform=`detect_os`
leetcode_url=$1

get_question_slug ${leetcode_url}

dir_name=`echo ${QUESTION_TITLE_SLUG} | awk -F '-' '{for (i=1; i<=NF; i++) printf("%s", toupper(substr($i,1,1)) substr($i,2)) }'`

dir_name=`echo ${dir_name:0:1} | tr '[A-Z]' '[a-z]'`${dir_name:1}

mkdir -p ${dir_name}
echo "Step 1 : Created \"${dir_name}\" directory!"
cd ${dir_name}
 
file=`${SCRIPTPATH}/comments.sh ${leetcode_url} | grep updated | awk '{print $1}'`
echo "Step 2 : Created \"${dir_name}/${file}\" source file!"
 
git add ${file}
echo "Step 3 : Run \"git add ${dir_name}/${file}\"!"

vi "${file}"
echo "Step 4 : Edited the \"${dir_name}${file}\"!"

output=`${SCRIPTPATH}/readme.sh ${file}`
readme=`echo "${output}" | head -n 1`
commit=`echo "${output}" | tail -n 1`

if [[ "$platform" == "macos" ]]; then
    echo $readme | pbcopy
else
    echo $readme
    read -n 1 -s -r -p  "Please copy the line above & press any key continue to edit README.md"
fi

echo "Step 5 : Copied the readme text to Clipboard!"
vi ${SCRIPTPATH}/../README.md
echo "Step 6 : Edited the \"README.md\"!"

echo "Step 7 : You can commit the changes by running the following command line..."
echo ""
echo "            ${commit}"