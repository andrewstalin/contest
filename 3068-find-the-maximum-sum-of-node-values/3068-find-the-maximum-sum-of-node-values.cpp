class Solution {
public:

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        std::vector<std::vector<int64_t>> dp(nums.size() + 1, vector<int64_t>(2, 0));
        dp[nums.size()][1] = 0;
        dp[nums.size()][0] = INT64_MIN;
        
        for (int i = (nums.size() - 1); i >= 0; --i) {
            for (int j = 0; j <= 1; ++j) {
                int64_t val1 = dp[i + 1][j ^ 1] + (nums[i] ^ k);
                int64_t val2 = dp[i + 1][j] + nums[i];

                dp[i][j] = std::max(val1, val2);
            }
        }
        
        return dp[0][1];
    }
};