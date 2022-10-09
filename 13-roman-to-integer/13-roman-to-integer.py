class Solution:
    def romanToInt(self, s: str) -> int:
        SUM   = 0
        Roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        Flag  = False
        Just  = False
        Subst = {'IV': 4, 'IX': 9,
                 'XL': 40, 'XC': 90,
                 'CD': 400, 'CM': 900}
    
        for i in range(len(s)):
            SUM += Roman[s[i]]
            
            if s[i] in ['I', 'X', 'C']:
                Flag = True
            else: Flag = False

            if i < len(s) - 1:
                if Just is True:
                    Just = False
                    pass
            
                if Flag:
                    target = s[i] + s[i + 1]
                
                    if target in Subst.keys():
                        SUM += Subst[target]
                        SUM -= Roman[s[i]] + Roman[s[i + 1]]
                        Just = True
                        
        return SUM