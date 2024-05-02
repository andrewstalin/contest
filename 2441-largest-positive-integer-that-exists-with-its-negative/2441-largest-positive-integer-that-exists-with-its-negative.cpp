class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::vector<bool> data(2001, false);
        for (int i = 0; i < nums.size(); ++i) {
            data[nums[i] + 1000] = true;
        }
        
        int l = 0;
        int r = 2000;
        
        while (l < r) {
            if (data[l] && data[r]) {
                return r - 1000;
            }
            
            ++l;
            --r;
        }
        
        return -1;
    }
};