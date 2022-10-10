class Solution {
public:
    string breakPalindrome(string palindrome) {
        string ret = "";
        short len = palindrome.length();
        
        if (palindrome.length() == 1) return ret;
        
        ret = palindrome;
        bool isAllA = true;
        for (short i = 0; i < len / 2; i++) {
            if (palindrome[i] != 'a') isAllA = false;
        }
        
        if (isAllA) {
            ret[len - 1] = 'b';
            return ret;
        }
        
        for (short i = 0; i < len / 2; i++) {
            if (palindrome[i] != 'a') {
                ret[i] = 'a';
                return ret;
            };
        }
        
        return ret;
    }
};