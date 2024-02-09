class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        
        std::vector<std::pair<int, int>> dp(nums.size(), std::make_pair<int, int>(0, -1));
        dp[0].first = 1;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); ++i) {
            int next = -1;
            int max = 0;
            
            for (int j = i - 1; j >= 0; --j) {
               if (nums[i] % nums[j] == 0 && dp[j].first > max) {
                   max = dp[j].first;
                   next = j;
               } 
            }
            
            dp[i].first = max + 1;
            dp[i].second = next;
        }
        
        int max = 1;
        int index = 0;
        
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i].first > max) {
                max = dp[i].first;
                index = i;
            }
        }
        
        std::vector<int> res;
        
        while (index != -1) {
            res.emplace_back(nums[index]);
            index = dp[index].second;
        }
        
        return res;
    }
};