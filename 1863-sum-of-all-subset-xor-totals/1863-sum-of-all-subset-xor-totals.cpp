class Solution {
public:
    
    int func(size_t pos, int val, const std::vector<int>& nums) {
        if (pos >= nums.size()) {
            return val;
        }
        
        int res = func(pos + 1, val, nums);
        val ^= nums[pos];
        res += func(pos + 1, val, nums);
        return res;
    }
    
    int subsetXORSum(vector<int>& nums) {
        return func(0, 0, nums);
    }
};