class Solution {
public:
    int inline max(const std::vector<int>& nums) {
        int res = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            res = std::max(res, nums[i]);
        }
        return res;
    }
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return max(nums2) - max(nums1);
    }
};