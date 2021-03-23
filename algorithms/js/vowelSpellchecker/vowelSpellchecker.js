// Source : https://leetcode.com/problems/vowel-spellchecker/
// Author : Harvey Cao
// Date   : 2021-03-23

/********************************************************************************** 
* 966. Vowel Spellchecker 
* Given a wordlist, we want to implement a spellchecker that converts a query word 
* into a correct word.
*               
**********************************************************************************/


/**
 * @param {string[]} wordlist
 * @param {string[]} queries
 * @return {string[]}
 */
 var spellchecker = function(wordlist, queries) {
    const map = new Map();
    for (const word of wordlist) {
        let lower = word.toLowerCase();
        if (!map.has(lower)) map.set(lower, new Set());
        map.set(lower, map.get(lower).add(word));
        let lowerReg = lower.replace(/a|e|i|o|u/g, "*");
        if (!map.has(lowerReg)) map.set(lowerReg, new Set());
        map.set(lowerReg, map.get(lowerReg).add(word));
    }
    let res = [];
    for (const query of queries) {
        let lower = query.toLowerCase();
        if (map.has(lower)) {
            let wordSets = map.get(lower);
            if (wordSets.has(query)) {
                res.push(query);    
            } else {
                res.push(wordSets.values().next().value);
            }
        } else {
            let lowerReg = lower.replace(/a|e|i|o|u/g, "*");
            if (map.has(lowerReg)) {
                res.push(map.get(lowerReg).values().next().value);
            } else {
                res.push("");
            }
        }
    }
    return res;
};