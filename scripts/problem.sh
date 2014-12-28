#!/bin/sh

grep Source $1 | sed -e "s/\/\/ Source : //g" | xargs -I'{}' xidel {} -q -e "css('div.question-content')"  | grep -v '                ' |sed '/^$/N;/^\n$/D'  |sed 's/^/* /' | sed "1i/*$(printf '%.0s*' {0..80}) \n* " | sed "\$a $(printf '%.0s*' {0..80})*/\n" > /tmp/tmp.txt; sed -i '4 r /tmp/tmp.txt' $1 
