class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<int> data(51, 0);
        for (int v : nums1) {
            ++data[v];
        }
        
        int res = 0;
        int val;
        
        for (int v : nums2) {
            val = v*k;
            
            if (val > 50) {
                continue;
            }
            
            if (val == 1) {
                res += nums1.size();
                continue;
            }
            
            for (int i = 1, num = val; num < 51; ++i, num = val*i) {
                res += data[num];
            }
        }
        
        return res;
    }
};