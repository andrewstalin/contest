class Solution {
public:
    inline int forward(int val, int pos, const std::vector<int>& nums) {
        while (pos + 1 < nums.size() && nums[pos + 1] == val) {
            ++pos;
        }
        return pos;
    }
    
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        
        int l = forward(nums[0], 0, nums);
        
        if (l + 1 >= nums.size()) {
            return 1;
        }
        
        int r = l + 1;
        int res = 2;
        bool increase = nums[r] > nums[l];
        
        while (r < nums.size()) {
            if (increase) {
                if (nums[r] > nums[r - 1]) {
                    ++r;
                } else {
                    res = std::max(res, r - l);
                    l = forward(nums[r - 1], r - 1, nums);
                    r = l + 1;
                    
                    if (l + 1 >= nums.size()) {
                        break;
                    }
                    
                    increase = nums[r] > nums[l];
                }
            } else {
                if (nums[r] < nums[r - 1]) {
                    ++r;
                } else {
                    res = std::max(res, r - l);
                    l = forward(nums[r - 1], r - 1, nums);
                    r = l + 1;
                    
                    if (l + 1 >= nums.size()) {
                        break;
                    }
                    
                    increase = nums[r] > nums[l];
                }
            }
        }
        
        return std::max(res, r - l);
    }
};