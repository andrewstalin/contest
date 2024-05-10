class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        return nums2[0] - nums1[0];
    }
};