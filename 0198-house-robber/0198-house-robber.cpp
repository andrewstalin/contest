class Solution {
public:

    int func(int pos, const std::vector<int>& nums, std::vector<int>& dp) {
        if (pos >= nums.size()) {
            return 0;
        }
        
        if (dp[pos] != -1) {
            return dp[pos];
        }
        
        dp[pos] = nums[pos] + func(pos + 2, nums, dp);
        dp[pos] = std::max(dp[pos], func(pos + 1, nums, dp));
        
        return dp[pos];
    }
    
    int rob0(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        std::vector<int> dp(nums.size(), -1);
        return func(0, nums, dp);
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int v1 = nums.back();
        int v2 = 0;
        int v;
        
        for (int i = (nums.size() - 2); i >= 0; --i) {
            v = std::max(nums[i] + v2, v1);
            v2 = v1;
            v1 = v;
        }
        
        return v1;
    }
    
};