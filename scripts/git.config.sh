#!/bin/bash
set -e

case $1 in
    -l) SCOPE="--local"
        ;;
    -g) SCOPE="--global"
        ;;
    *) SCOPE="--local"
        ;;
esac


OPTIONS="${SCOPE} --replace-all"
CMD="git config ${OPTIONS}"

${CMD} alias.lg0  "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --"
${CMD} alias.lg1  "log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all"
${CMD} alias.lg2  "log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''          %C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all"
${CMD} alias.lg  !"git lg0"

