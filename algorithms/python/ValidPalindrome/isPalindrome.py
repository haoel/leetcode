class Solution:
    def isPalindrome(self, s: str) -> bool:
        temp = ""
        
        for i in s:
            if i.isalpha() or i.isdigit():
                temp = (temp+i).lower()
        
        if temp[::-1] != temp:
            return False
        else:
            return True