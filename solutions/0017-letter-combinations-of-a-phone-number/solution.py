class Solution(object):

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        map = {1:"","2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}

        if len(digits) ==1:
            return list(map[digits])
        else:
            output = []
            last = self.letterCombinations(digits[0:len(digits)-1])
            for value in last:
                for letter in map[digits[-1]]:
                    output.append(value + letter)

            return output
        
