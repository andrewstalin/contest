class Solution {
public:
    int longestIdealString(string s, int k) {
        if (s.size() == 1) {
            return 1;
        }
        
        std::vector<int> dp(26, 0);
        dp[s.back() - 'a'] = 1;
        
        int res = 0;
        
        for (int i = (s.size() - 2); i >= 0; --i) {
            int index = s[i] - 'a';
            int right = (s[i] + k > 'z' ? 'z' : s[i] + k) - 'a';
            int left = (s[i] - k < 'a' ? 'a' : s[i] - k) - 'a';

            for (int j = index; j <= right; ++j) {
                dp[index] = std::max(dp[index], dp[j]);
            }
            
            for (int j = index - 1; j >= left; --j) {
                dp[index] = std::max(dp[index], dp[j]);
            }
            
            ++dp[index];
            res = std::max(res, dp[index]);
        }
        
        return res;
    }
};