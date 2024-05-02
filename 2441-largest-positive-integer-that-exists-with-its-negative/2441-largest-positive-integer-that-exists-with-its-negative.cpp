class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        std::vector<bool> data(2001, false);
        
        for (int i = 0; i < nums.size(); ++i) {
            int val = std::abs(nums[i]);
            
            if (val > res && data[1000 - nums[i]]) {
                res = val;
            }
            
            data[nums[i] + 1000] = true;
        }
        
        return res;
    }
};