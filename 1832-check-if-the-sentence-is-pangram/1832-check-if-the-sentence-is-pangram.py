class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        isExist = [0 for _ in range(26)]
        
        for s in sentence:
            isExist[ord(s) - 97] = 1
        
        if 0 in isExist: return False
        else:            return True