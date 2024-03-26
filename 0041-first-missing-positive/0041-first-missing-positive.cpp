class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool done = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                done = false;
                break;
            }
        }
        
        if (done) {
            return 1;
        }

        int k = 0;
        
        while (k < nums.size()) {
            if (nums[k] <= 0 || nums[k] > nums.size() || nums[nums[k] - 1] == nums[k]) {
                ++k;
                continue;
            }
            
            std::swap(nums[k], nums[nums[k] - 1]);
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != (nums[i - 1] + 1)) {
                return i + 1;
            }
        }
        
        return nums.size() + 1; 
    }
};