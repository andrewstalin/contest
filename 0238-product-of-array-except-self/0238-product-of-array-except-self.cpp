class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int64_t> right(nums.size(), 1);
        int64_t val = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            right[i] = val;
            val *= nums[i];
        }
        
        std::vector<int> res(nums.size(), 0);
        int64_t left = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = left*right[i];
            left *= nums[i];
        }
        
        return res;
    }
};