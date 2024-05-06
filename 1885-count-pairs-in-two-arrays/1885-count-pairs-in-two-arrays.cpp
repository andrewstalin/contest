class Solution {
public:
    
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> diff(nums1.size(), 0);
        
        for (int i = 0; i < nums1.size(); ++i) {
            diff[i] = nums1[i] - nums2[i];
        }
        
        std::sort(diff.begin(), diff.end());
        
        long long sum = 0;
        int l = 0;
        int r = diff.size() - 1;
        
        while (l < r) {
            if (diff[l] + diff[r] <= 0) {
                ++l;
            } else {
                sum += (r - l);
                --r;
            }
        }
        
        
        return sum;
    }
};