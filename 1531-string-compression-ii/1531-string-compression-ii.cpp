class Solution {
public:
    int getLengthOfOptimalCompression(string s, int K) {
        int n = s.length();
        
        vector<int> v(K + 1, n);
        vector<vector<int>> dp(n + 1, v);
        
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= K; k++) {
                if (k > 0)
                    dp[i][k] = min(dp[i][k], dp[i - 1][k - 1]);
                
                int same = 0,dif = 0;
                
                for (int j = i; j >= 1; j--) {
                    if (s[j - 1] == s[i - 1])
                        same++;
                    
                    else
                        dif++;
                    
                    if (dif > k)
                        break;
                    
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - dif] + getCount(same));
                }
            }
        }
        
        return dp[n][K];
    }
    
    int getCount (int same) {
        if(same == 1)  return 1;
        
        if(same < 10)  return 2;
        
        if(same < 100) return 3;
        
        else           return 4;
    }
};