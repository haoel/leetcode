#!/bin/bash
set -e

pushd `dirname $0` > /dev/null
SCRIPT_PATH=`pwd -P`
popd > /dev/null
SCRIPT_FILE=`basename $0`

COLOR_INFO='\033[0;36m'
COLOR_NONE='\033[0m'

source ${SCRIPT_PATH}/lib/query_problem.sh

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

function git_commit(){
    TITLE=$1
    FILE1=$2
    FILE2=$3
    git commit -m "New Problem Solution - \"${TITLE}\""  "${FILE1}" "${FILE2}"
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

file=`${SCRIPT_PATH}/comments.sh ${leetcode_url} | grep updated | awk '{print $1}'`
WORKING_DIR=`pwd`
SRC="${dir_name}/${file}"
SRC_FILE="${WORKING_DIR}/${file}"
README_FILE="${SCRIPT_PATH}/../README.md"

echo "Step 2 : Created \"${SRC}\" source file!"

echo "Step 3 : Run \"git add ${SRC}\"!"
git add ${SRC_FILE}

vi "${SRC_FILE}"
echo "Step 4 : Edited the \"${SRC}\"!"
readme=`${SCRIPT_PATH}/readme.sh ${file}`
readme=`echo "${readme}" | head -n 1`

if [[ "$platform" == "macos" ]]; then
    echo $readme | pbcopy
else
    echo $readme
    read -n 1 -s -r -p  "Please copy the line above & press any key continue to edit README.md"
fi
echo "Step 5 : Copied the readme text to Clipboard!"
vi ${README_FILE}

echo "Step 6 : Edited the \"README.md\"!"

QUESTION_FRONTEND_ID=`echo "${readme}" | awk -F '|' '{print $2}'`
QUESTION_DIFFICULTY=`echo "${readme}" | awk -F '|' '{print $5}'`
QUESTION_TITLE=`echo "${readme}" | awk -F '|' '{print $3}' | sed 's/\[/\]/' |awk -F ']' '{print $2}'`
commit="git commit -m \"New Problem Solution - \\\"${QUESTION_FRONTEND_ID}. ${QUESTION_TITLE}\\\"\""

echo "Step 7 : It's ready to commit to git repository ..."
echo ""
echo "      ${commit} \\"
echo "          ${SRC_FILE} \\"
echo "          ${README_FILE}"
echo ""

#git status

commit="${commit} \"${WORKING_DIR}/${file}\" \"${SCRIPT_PATH}/../README.md\""

while true; do
    read -p "Do you wish to commit them (y/n) ? " yn
    case $yn in
        [Yy]* ) git_commit "${QUESTION_FRONTEND_ID}. ${QUESTION_TITLE}" "${SRC_FILE}" "${README_FILE}" ; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done

echo "Done!"