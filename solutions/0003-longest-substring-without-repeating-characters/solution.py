class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = 0
        longest = ""
        for i in range(len(s)):
            temp= s[i]
            j=1
            while i +j < len(s) and not (s[i+j] in temp)  :
                temp += s[i+j]
                j+=1
            i += j 
            if len(temp)  > count:
                count = len(temp) 
                

            
        return count

        
