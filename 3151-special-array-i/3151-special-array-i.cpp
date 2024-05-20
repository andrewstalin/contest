class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int v1, v2;
        
        for (size_t i = 0, end = nums.size() - 1; i < end; ++i) {
            v1 = nums[i] % 2;
            v2 = nums[i + 1] % 2; 
            
            if ((v1 && v2) || (!v1 && !v2)) {
                return false;
            }
        }
        
        return true;
    }
};