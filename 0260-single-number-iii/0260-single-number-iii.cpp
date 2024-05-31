class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) {
            return nums;
        }
        
        int64_t mask = 0;
        for (int num : nums) {
            mask ^= num;
        }
        
        int64_t val1 = 0;
        int64_t rightmost_bit = (mask & (-mask));
        
        for (int num : nums) {
            if ((num & rightmost_bit) != 0) {
                val1 ^= num;
            }
        }
        
        return std::vector<int>{ static_cast<int>(val1), static_cast<int>(mask ^ val1)};
    }
};