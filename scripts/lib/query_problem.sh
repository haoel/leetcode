#!/bin/bash

LEETCODE_URL=https://leetcode.com/problems/
LEETCODE_NEW_URL=https://leetcode.com/problems/
LEETCODE_OLD_URL=https://oj.leetcode.com/problems/


function get_question_slug()
{
    QUESTION_TITLE_SLUG=${1#${LEETCODE_URL}}
    QUESTION_TITLE_SLUG=$(echo $QUESTION_TITLE_SLUG | sed 's/\/.*//g') # remove the needless url path
}

function query_problem_xidel() 
{
    # xidel change the -q option to -s after 0.9.4 version, so we have to check that
    # if xidel has -q option, then it will return error. 

    OPT=

    set +e
    xidel -q 2>/dev/null
    if [ $? -ne 0 ]; then
       OPT=-q
    else
       # if xidel has -s option, then it will return error. 
       xidel -s 2>/dev/null
       if  [ $? -ne 0 ]; then
           OPT=-s
       fi
    fi 
    set -e

    QUESTION_CONTENT=$(xidel ${OPT} ${TMP_JSON_FILE} -e '$json("data").question.content' | sed -e 's/<[^>]*>//g; s/&nbsp;/ /g; s/&amp;/\&/g; s/&lt;/\</g; s/&gt;/\>/g; s/&quot;/\"/g; s/&#39;/\'"'"'/g; s/&ldquo;/\"/g;')

    QUESTION_DIFFICULTY=$(xidel ${OPT} ${TMP_JSON_FILE} -e '$json("data").question.difficulty')

    QUESTION_TITLE=$(xidel ${OPT} ${TMP_JSON_FILE} -e '$json("data").question.title')

    QUESTION_ID=$(xidel ${OPT} ${TMP_JSON_FILE} -e '$json("data").question.questionId')

    QUESTION_FRONTEND_ID=$(xidel ${OPT} ${TMP_JSON_FILE} -e '$json("data").question.questionFrontendId')

    #QUESTION_CATEGORY=$(xidel ${OPT} ${TMP_JSON_FILE} -e '$json("data").question.categoryTitle')    
}

function query_problem_jq() 
{
    QUESTION_CONTENT=$(jq -r '.data.question.content' ${TMP_JSON_FILE} | sed -e 's/<sup>/\^/g' | sed -e 's/<[^>]*>//g; s/&nbsp;/ /g; s/&amp;/\&/g; s/&lt;/\</g; s/&gt;/\>/g; s/&quot;/\"/g; s/&#39;/\'"'"'/g; s/&ldquo;/\"/g;')

    QUESTION_DIFFICULTY=$(jq -r '.data.question.difficulty' ${TMP_JSON_FILE})

    QUESTION_TITLE=$(jq -r '.data.question.title' ${TMP_JSON_FILE})

    QUESTION_ID=$(jq -r '.data.question.questionId' ${TMP_JSON_FILE})

    QUESTION_FRONTEND_ID=$(jq -r '.data.question.questionFrontendId' ${TMP_JSON_FILE})
 
}

function query_problem()
{
    TMP_JSON_FILE=tmp.json

#    curl -s "https://leetcode.com/graphql?query=query%20getQuestionDetail(%24titleSlug%3A%20String!)%20%7B%0A%20%20isCurrentUserAuthenticated%0A%20%20question(titleSlug%3A%20%24titleSlug)%20%7B%0A%20%20%20%20questionId%0A%20%20%20%20questionFrontendId%0A%20%20%20%20questionTitle%0A%20%20%20%20translatedTitle%0A%20%20%20%20questionTitleSlug%0A%20%20%20%20content%0A%20%20%20%20translatedContent%0A%20%20%20%20difficulty%0A%20%20%20%20stats%0A%20%20%20%20contributors%0A%20%20%20%20similarQuestions%0A%20%20%20%20discussUrl%0A%20%20%20%20mysqlSchemas%0A%20%20%20%20randomQuestionUrl%0A%20%20%20%20sessionId%0A%20%20%20%20categoryTitle%0A%20%20%20%20submitUrl%0A%20%20%20%20interpretUrl%0A%20%20%20%20codeDefinition%0A%20%20%20%20sampleTestCase%0A%20%20%20%20enableTestMode%0A%20%20%20%20metaData%0A%20%20%20%20enableRunCode%0A%20%20%20%20enableSubmit%0A%20%20%20%20judgerAvailable%0A%20%20%20%20infoVerified%0A%20%20%20%20envInfo%0A%20%20%20%20urlManager%0A%20%20%20%20article%0A%20%20%20%20questionDetailUrl%0A%20%20%20%20discussCategoryId%0A%20%20%20%20discussSolutionCategoryId%0A%20%20%20%20libraryUrl%0A%20%20%20%20companyTags%20%7B%0A%20%20%20%20%20%20name%0A%20%20%20%20%20%20slug%0A%20%20%20%20%20%20translatedName%0A%20%20%20%20%7D%0A%20%20%20%20topicTags%20%7B%0A%20%20%20%20%20%20name%0A%20%20%20%20%20%20slug%0A%20%20%20%20%20%20translatedName%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20interviewed%20%7B%0A%20%20%20%20interviewedUrl%0A%20%20%20%20companies%20%7B%0A%20%20%20%20%20%20id%0A%20%20%20%20%20%20name%0A%20%20%20%20%20%20slug%0A%20%20%20%20%7D%0A%20%20%20%20timeOptions%20%7B%0A%20%20%20%20%20%20id%0A%20%20%20%20%20%20name%0A%20%20%20%20%7D%0A%20%20%20%20stageOptions%20%7B%0A%20%20%20%20%20%20id%0A%20%20%20%20%20%20name%0A%20%20%20%20%7D%0A%20%20%7D%0A%20%20subscribeUrl%0A%20%20isPremium%0A%20%20loginUrl%0A%7D%0A&operationName=getQuestionDetail&variables=%7B%22titleSlug%22%3A%22${2}%22%7D" > ${TMP_JSON_FILE} 

    #
    # NOTE: leetcode server supports `br` encoding and make it high priority. But curl doesn't support it, 
    #       So, you need make sure the `accept-encoding` hasn't br in the request header.
    #       (if you copy & paste the curl script from Chrome, the `br` could be added!)
    #
    curl -s 'https://leetcode.com/graphql' \
    -H 'origin: https://leetcode.com' \
    -H 'accept-encoding: gzip, deflate' \
    -H 'accept-language: zh-CN,zh;q=0.9,und;q=0.8,en;q=0.7' \
    -H 'cookie: __cfduid=dae082e425ee3916c04a5170b832e268e1524142659; _ga=GA1.2.1432146910.1524142661; _gid=GA1.2.650843898.1529736240; csrftoken=iSKedVXxGDkBBXbP9chsyXhbIrRedF7iw2EMRZiemtzKD8vjHSWZJKkKQVIwZKp7; __atuvc=2%7C25; __atuvs=5b2ded02313c83c4001; _gat=1' \
    -H 'x-csrftoken: iSKedVXxGDkBBXbP9chsyXhbIrRedF7iw2EMRZiemtzKD8vjHSWZJKkKQVIwZKp7' \
    -H 'pragma: no-cache' \
    -H 'content-type: application/json' \
    -H 'accept: */*' -H 'cache-control: no-cache' \
    -H 'authority: leetcode.com' \
     -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.87 Safari/537.36' \
    -H "referer: ${1}" \
    --data-binary '{"operationName":"questionData","variables":{"titleSlug":"'${2}'"},"query":"query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    langToValidPlayground\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    envInfo\n    __typename\n  }\n}\n"}' --compressed > ${TMP_JSON_FILE}

    query_problem_jq

    rm -f ${TMP_JSON_FILE}
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

function install_brew() 
{
    TRUE_CMD=`which true`
    brew=`type -P brew || ${TRUE_CMD}`
    if [ -z "${brew}" ]; then
        echo "brew not found !"
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
    fi
}


function manually_install_jq() {
    echo "Unknown platform, please install 'jq' manually!"
    echo "Dowload Site: https://stedolan.github.io/jq/download/"
}
function install_jq() 
{
    echo "Install jq ..."
    
    platform=`detect_os`

    if [[ "$platform" == "unknown" ]]; then
        manually_install_jq
        exit 1;
    fi

    if [[ "$platform" == "linux" ]]; then
        OS_RELEASE="/etc/os-release"
        if [ ! -f ${OS_RELEASE} ]; then
            manually_install_jq
            exit 1;
        fi
        DISTRO=`awk -F= '/^NAME/{print $2}' `
        DISTRO="CentOS Linux"
        case $DISTRO in
            Ubuntu* ) sudo apt-get install jq
                     ;;
            CentOS* ) echo sudo yum install jq
                     ;;
                 * ) manually_install_jq 
                     exit 1;
        esac
    fi

    if [[ "$platform" == "macos" ]]; then
        install_brew
        echo "brew install jq..."
        brew install jq
    fi

    echo "Install jq successfullly !"
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
    xidel_ver=0.9.8
    if [[ "$platform" == "linux" ]]; then
        hardware=`uname -m`
        xidel_tar=xidel-${xidel_ver}.linux64.tar.gz
        case $hardware in
            x86_64 )    xidel_tar=xidel-${xidel_ver}.linux64.tar.gz
                        ;;
              i686 )    xidel_tar=xidel-${xidel_ver}.linux32.tar.gz
                        ;;
                 * )    echo "Cannot install xidel, please install it manually!"
                        exit 1;
        esac
        if [ ! -f ${xidel_tar} ]; then
            echo "Downloading xidel......"
            curl -# -L https://github.com/benibela/xidel/releases/download/Xidel_${xidel_ver}/${xidel_tar} -o ${xidel_tar}
        fi
        tar -zxvf ${xidel_tar}
        sudo ./install.sh
    fi

    #install the xidel on MacOS platform
    #refer to: https://www.evernote.com/shard/s69/sh/ff1e78f3-a369-4855-b18f-6184ce789c45/f3511927d0fb356ce883835f2eb712e0
    if [[ "$platform" == "macos" ]]; then
        install_brew
        echo "brew install xidel..."
        brew install xidel
    fi

    cd ..
    echo "Install xidel successfullly !"
}
