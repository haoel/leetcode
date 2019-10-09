class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if not s or len(s)<len(p):
            return []
        dictS = dict()
        dictP = dict()
        tam = len(p)
        answer = []
        for i in range(tam):
            if p[i] not in dictP:
                dictP[p[i]] = 1
            else:
                dictP[p[i]] = dictP[p[i]]+1
            if s[i] not in dictS:
                dictS[s[i]] = 1
            else:
                dictS[s[i]] = dictS[s[i]]+1
        if dictS==dictP:
            answer.append(0)
        for j in range(1,len(s)-len(p)+1):
            dictS[s[j-1]] = dictS[s[j-1]]-1
            
            if dictS[s[j-1]] == 0:
                dictS.pop(s[j-1])
            
            if s[j+tam-1] not in dictS:
                dictS[s[j+tam-1]] = 1
            else:
                dictS[s[j+tam-1]] = dictS[s[j+tam-1]] + 1
            if dictS==dictP:
                answer.append(j)
        return answer
