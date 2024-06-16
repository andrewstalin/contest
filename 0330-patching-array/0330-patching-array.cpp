class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        uint32_t end = n;
        int res = nums[0] != 1;
        uint32_t k = 1;
        size_t i = nums[0] == 1 ? 1 : 0;
        
        while (i < nums.size() && k < end) {
            if (k + 1 < nums[i]) {
                k += (k + 1);
                ++res;
                continue;
            }
            
            k += nums[i];
            ++i;
        }
        
        while (k < n) {
            ++res;
            k += (k + 1);
        }
        
        return res;
    }
};
