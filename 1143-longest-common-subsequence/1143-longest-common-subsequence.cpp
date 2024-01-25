class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<int> dp(text2.size() + 1, 0);
        int prev, val;
        
        for (int i1 = (text1.size() - 1); i1 >= 0; --i1) {
            prev = 0;
            
            for (int i2 = (text2.size() - 1); i2 >= 0; --i2) {
                val = std::max(dp[i2], prev);
                
                if (text1[i1] == text2[i2]) {
                    val = std::max(val, 1 + dp[i2 + 1]);
                }
                
                dp[i2 + 1] = prev;
                prev = val;
            }
            
            dp[0] = prev;
        }
        
        return dp[0];
    }
};