class Solution {
public:
    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int remain = nums.size();
        int index = 0;
        int val;
        
        while (index < nums.size()) {
            if (nums[index] >= remain && (index == 0 || nums[index - 1] < remain)) {
                return remain;
            }
            
            val = nums[index];
            while (index < nums.size() && nums[index] == val) {
                ++index;
                --remain;
            }
        }
        
        return -1;
    }
};