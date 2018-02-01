#!/bin/bash

LEETCODE_URL=https://leetcode.com/problems/
LEETCODE_NEW_URL=https://leetcode.com/problems/
LEETCODE_OLD_URL=https://oj.leetcode.com/problems/


function get_question_slug()
{
    QUESTION_TITLE_SLUG=${1#${LEETCODE_URL}}
    QUESTION_TITLE_SLUG=$(echo $QUESTION_TITLE_SLUG | sed 's/\/.*//g') # remove the needless url path
}

function query_problem()
{
    TMP_JSON_FILE=tmp.json

    curl -s 'https://leetcode.com/graphql' \
    -H 'origin: https://leetcode.com' \
    -H 'accept-encoding: gzip, deflate, br' \
    -H 'accept-language: zh-CN,zh;q=0.9,und;q=0.8,en;q=0.7' \
    -H 'cookie: __atuvc=3%7C8%2C0%7C9%2C0%7C10%2C0%7C11%2C11%7C12; _ga=GA1.2.714733890.1464506754; __cfduid=d0091b1a13637142e21e82f5f43f8f3c61517304755; _gid=GA1.2.846248999.1517304756; csrftoken=W3F3gDMAmFE1024RMhNLUi0ofHb4gJ5Wqt4GcOaZHJKneSuXkY7kq2vHm6mA8f12; _gat=1' \
    -H 'x-csrftoken: W3F3gDMAmFE1024RMhNLUi0ofHb4gJ5Wqt4GcOaZHJKneSuXkY7kq2vHm6mA8f12' \
    -H 'pragma: no-cache' \
    -H 'content-type: application/json' \
    -H 'accept: */*' -H 'cache-control: no-cache' \
    -H 'authority: leetcode.com' \
    -H "referer: ${1}" \
    --data-binary '{"operationName":"getQuestionDetail","variables":{"titleSlug":"'${2}'"},"query":"query getQuestionDetail($titleSlug: String!) {\n  isCurrentUserAuthenticated\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    questionTitle\n    questionTitleSlug\n    content\n    difficulty\n    stats\n    contributors\n    companyTags\n    topicTags\n    similarQuestions\n    discussUrl\n    mysqlSchemas\n    randomQuestionUrl\n    sessionId\n    categoryTitle\n    submitUrl\n    interpretUrl\n    codeDefinition\n    sampleTestCase\n    enableTestMode\n    metaData\n    enableRunCode\n    enableSubmit\n    judgerAvailable\n    infoVerified\n    envInfo\n    urlManager\n    article\n    questionDetailUrl\n    discussCategoryId\n    discussSolutionCategoryId\n  }\n  interviewed {\n    interviewedUrl\n    companies {\n      id\n      name\n    }\n    timeOptions {\n      id\n      name\n    }\n    stageOptions {\n      id\n      name\n    }\n  }\n  subscribeUrl\n  isPremium\n  loginUrl\n}\n"}' --compressed > ${TMP_JSON_FILE}

    QUESTION_CONTENT=$(xidel -q ${TMP_JSON_FILE} -e '$json("data").question.content' | sed -e 's/<[^>]*>//g')

    QUESTION_DIFFICULTY=$(xidel -q ${TMP_JSON_FILE} -e '$json("data").question.difficulty')

    QUESTION_TITLE=$(xidel -q ${TMP_JSON_FILE} -e '$json("data").question.questionTitle')

    QUESTION_ID=$(xidel -q ${TMP_JSON_FILE} -e '$json("data").question.questionId')

    QUESTION_CATEGORY=$(xidel -q ${TMP_JSON_FILE} -e '$json("data").question.categoryTitle')
    
    rm -f $TMP_JSON_FILE
}
