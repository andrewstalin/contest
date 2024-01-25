class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        
        for (int i1 = (text1.size() - 1); i1 >= 0; --i1) {
            for (int i2 = (text2.size() - 1); i2 >= 0; --i2) {
                dp[i1][i2] = std::max(dp[i1 + 1][i2], dp[i1][i2 + 1]);
                
                if (text1[i1] == text2[i2]) {
                    dp[i1][i2] = std::max(dp[i1][i2], 1 + dp[i1 + 1][i2 + 1]);
                }
            }
        }
        
        return dp[0][0];
    }
};