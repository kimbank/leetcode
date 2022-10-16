class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (d > jobDifficulty.size()) {
            return -1;
        }
        
        vector<int> v(jobDifficulty.size());
        vector<vector<int>> dp(d, v);
        int diff = 0;
        
        for (int i = 0; i < jobDifficulty.size(); i++) {
            diff = max(diff, jobDifficulty[i]);
            dp[0][i] = diff;
        }
        
        for (int i = 1; i < d; i++) {
            for (int j = 1; j < jobDifficulty.size(); j++) {
                diff = 0;
                dp[i][j] = INT_MAX;
                
                for (int k = j; k >= i; k--) {
                    diff = max(diff, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], diff + dp[i-1][k-1]);
                }
            }
        }
        return dp[d -1][jobDifficulty.size() - 1];
    }
};