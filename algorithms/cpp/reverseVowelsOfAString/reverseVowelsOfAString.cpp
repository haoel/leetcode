// Source : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2016-04-30

/*************************************************************************************** 
 *
 * Write a function that takes a string as input and reverse only the vowels of a 
 * string.
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 ***************************************************************************************/

//Author: Calinescu Valentin
class Solution {
public:
    string reverseVowels(string s) {
        list <char> vowels;
        set <char> vows;
        vows.insert('a');
        vows.insert('A');
        vows.insert('e');
        vows.insert('E');
        vows.insert('i');
        vows.insert('I');
        vows.insert('o');
        vows.insert('O');
        vows.insert('u');
        vows.insert('U');
        string result;
        for(int i = 0; i < s.size(); i++)
        {
            if(vows.find(s[i]) != vows.end())
                vowels.push_back(s[i]);
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(vows.find(s[i]) != vows.end())
            {
                result.push_back(vowels.back());
                vowels.pop_back();
            }
            else
                result.push_back(s[i]);
        }
        return result;
    }
};


// Author: Hao Chen
// 1) preset a dictionary table to look up vowels
// 2) we have two pointer, the `left` one search vowels from the beginning to then end, the `right` one search from the end to the beginning.
// 3) swap the left one and the right one until left >= right.
class Solution {
private:
   bool vowelsTable[256];
public:
    Solution(){
        memset(vowelsTable, 0, sizeof(vowelsTable));
        vowelsTable['a']=true;
        vowelsTable['e']=true;
        vowelsTable['i']=true;
        vowelsTable['o']=true;
        vowelsTable['u']=true;
        
        vowelsTable['A']=true;
        vowelsTable['E']=true;
        vowelsTable['I']=true;
        vowelsTable['O']=true;
        vowelsTable['U']=true;
    }
    bool isVowels(char ch) {
        return vowelsTable[ch];
    }
    string reverseVowels(string s) {
        int left=0, right=s.size()-1;
        while ( left < right ) {
            while( !isVowels( s[left]) ) left++;
            while( !isVowels( s[right] ) ) right--;
            if (left >= right) break;
            swap(s[left], s[right]);
            left++; right--;
        }
        return s;
    }
};
