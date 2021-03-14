#!/bin/bash
set -e

AUTHOR="NOBODY"
COMMENT_TAG="//"
FILE_EXT=".cpp"

pushd `dirname $0` > /dev/null
SCRIPTPATH=`pwd -P`
popd > /dev/null
SCRIPTFILE=`basename $0`

COLOR_INFO='\033[0;36m'
COLOR_NONE='\033[0m'

source ${SCRIPTPATH}/lib/query_problem.sh

function usage()
{

    echo -e "Usage: ${0} [url] [source_file]"
    echo -e ""
    echo -e "Example:"
    echo -e ""
    echo -e "   1) Create a file named LargestNumber.cpp, and add Copyright & Problem description"
    echo -e "   ${0} https://leetcode.com/problems/largest-number/"
    echo -e ""
    echo -e "   2) Add Copyright & Problem description into existed file"
    echo -e "   ${0} https://leetcode.com/problems/largest-number/ LargestNumber.cpp"
    echo -e ""
}

function get_author_name()
{
    TRUE_CMD=`which true`
    git=`type -P git || ${TRUE_CMD}`
    if [ ! -z "${git}" ]; then
       AUTHOR=`git config --get user.name`
    else
       AUTHOR=`whoami`
    fi
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


if [ $# -lt 1 ] || [[ "${1}" != ${LEETCODE_NEW_URL}* ]] && [[ "${1}" != ${LEETCODE_OLD_URL}* ]]; then
    usage
    exit 255
fi

if [[ "${1}" == ${LEETCODE_OLD_URL}* ]]; then
    LEETCODE_URL=${LEETCODE_OLD_URL}
fi


leetcode_url=$1
current_time=`date +%Y-%m-%d`
platform=`detect_os`

get_question_slug ${leetcode_url}


TRUE_CMD=`which true`
xidel=`type -P xidel || ${TRUE_CMD}`
if [ -z "${xidel}" ]; then
    echo "xidel not found !"
    install_xidel
fi

#grab the problem information
query_problem ${leetcode_url} ${QUESTION_TITLE_SLUG}

if [ "${QUESTION_CATEGORY}" == "Shell" ]; then
    COMMENT_TAG='#'
    FILE_EXT='.sh'
fi

if [ $# -gt 1 ] && [ -f $2 ]; then
    source_file=$2
    if [[ "$platform" == "linux" ]]; then
        current_time=`stat -c %x ${source_file} | awk '{print \$1}'`
    elif [[ "$platform" == "macos" ]]; then
        current_time=`stat -f %a ${source_file} | xargs -I time date -r time +%Y-%m-%d`
    fi
else
    source_file=$QUESTION_TITLE_SLUG
    #source_file=${source_file::${#source_file}-1}
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

#detect the author name
get_author_name;

#adding the Copyright Comments
if  ! grep -Fq  "${COMMENT_TAG} Author :" $source_file ; then
    sed -i.bak '1i\'$'\n'"${COMMENT_TAG} Source : ${leetcode_url}"$'\n' $source_file
    sed -i.bak '2i\'$'\n'"${COMMENT_TAG} Author : ${AUTHOR}"$'\n' $source_file
    sed -i.bak '3i\'$'\n'"${COMMENT_TAG} Date   : ${current_time}"$'\n' $source_file
    sed -i.bak '4i\'$'\n'""$'\n' $source_file
    rm ${source_file}.bak
fi


#echo "--------------"
#echo "$QUESTION_CONTENT"
#echo $QUESTION_DIFFICULTY
#echo $QUESTION_TITLE
#echo $QUESTION_ID
#echo $QUESTION_CATEGORY
#echo "--------------"


function make_comments() {

    # arguments - comment content, style and the outputfile
    CONTENT=${1}
    STYLE=${2}
    OUTPUT_FILE=${3}

    # the width of comments
    WIDTH=100
    WIDTH_SEQ=$(seq 1 ${WIDTH})

    # 1) the `fold` command is used to wrap the text at centain column
    # 2) the last two `sed` commands are used to add the comments tags
    case ${STYLE} in
        clike )     echo "${CONTENT}" |
	                sed 's/^[[:space:]]*$/'"$(printf '\n')"'/g' | cat -s |     # replace the multiple empty line with a single empty line
                        fold -w ${WIDTH} -s  |                                     # wrap the text at centain column
                        sed 's/^/ * /'  |                                          # add the '*' for each line
			sed '1i\'$'\n'"/*$(printf '%.0s*' ${WIDTH_SEQ}) "$'\n' |   # add the first line - /***********
                        sed '2i\'$'\n'"@@@*"$'\n' | sed 's/^@@@/ /g' |             # add the second line -  * (lead by a space)
                        sed '$a\'$'\n'"@@@*$(printf '%.0s*' ${WIDTH_SEQ})*/"$'\n'| # add the end line - **********/
			sed 's/^@@@/ /' > ${OUTPUT_FILE}
                    ;;
        script )    echo "${CONTENT}" |
	                sed 's/^[[:space:]]*$/'"$(printf '\n')"'/g' | cat -s |     # replace the multiple empty line with a single empty line
                        fold -w ${WIDTH} -s  |                                     # wrap the text at centain column
                        sed 's/^/# /'  |                                           # add the '*' for each line
			sed '1i\'$'\n'"#$(printf '%.0s#' ${WIDTH_SEQ}) "$'\n' |    # add the first line - ############
                        sed '2i\'$'\n'"#"$'\n' |                                   # add the second line - #
                        sed '$a\'$'\n'"#$(printf '%.0s#' ${WIDTH_SEQ})"$'\n' > ${OUTPUT_FILE} # add the end line - #############
                    ;;
          * )       echo "Bad Comment Style!"
                    exit 1;
    esac
}

TMP_FILE=/tmp/tmp.txt
case ${FILE_EXT} in
     .c | .cpp | .java )
         make_comments  "${QUESTION_CONTENT}" clike "${TMP_FILE}"
         ;;
    .sh | .py )
         make_comments  "${QUESTION_CONTENT}" script "${TMP_FILE}"
         ;;
      * )
         echo "Bad file extension!"
         exit 1;
esac

#remove the ^M chars
tr -d $'\r' < ${TMP_FILE} > ${TMP_FILE}.1
mv ${TMP_FILE}.1 ${TMP_FILE}

#insert the problem description into the source file, and remove it
sed -i.bak '4 r '${TMP_FILE}'' ${source_file}
rm -f ${source_file}.bak
rm -f /tmp/tmp.txt

echo "${source_file} updated !"

