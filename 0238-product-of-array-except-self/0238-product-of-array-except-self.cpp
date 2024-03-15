class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res(nums.size(), 1);
        int val = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = val;
            val *= nums[i];
        }
        
        int left = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] *= left;
            left *= nums[i];
        }
        
        return res;
    }
};