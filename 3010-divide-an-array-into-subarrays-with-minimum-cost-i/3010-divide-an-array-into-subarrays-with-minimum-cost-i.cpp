class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int v1 = nums[1];
        int v2 = nums[2];
        
        if (v1 > v2) {
            std::swap(v1, v2);
        }
        
        for (int i = 3; i < nums.size(); ++i) {
            if (v1 >= nums[i]) {
                std::swap(v1, v2);
                v1 = nums[i];
            } else if (v2 > nums[i]) {
                v2 = nums[i];
            }
        }
        
        return v1 + v2 + nums[0];
    }
};