class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        
        while (i <= r) {
            if (nums[i] == 0) {
                std::swap(nums[l], nums[i]);
                ++l;
                ++i;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[r]);
                --r;
            } else {
                ++i;
            }
        }
    }
};