class Solution {
public:

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int v1 = nums.back();
        int v2 = 0;
        int v;
        
        for (int i = (nums.size() - 2); i >= 0; --i) {
            v = std::max(nums[i] + v2, v1);
            v2 = v1;
            v1 = v;
        }
        
        return v1;
    }
    
};