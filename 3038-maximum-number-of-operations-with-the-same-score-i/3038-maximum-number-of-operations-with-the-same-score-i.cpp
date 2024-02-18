class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = nums[0] + nums[1];
        int res = 1;
        
        for (int i = 2; i < (nums.size() - 1); i += 2) {
            if (nums[i] + nums[i + 1] == score) {
                ++res;
                continue;
            }
            
            break;
        }
        
        return res;
    }
};