class Solution {
public:

    
    vector<int> findErrorNums(vector<int>& nums) {
        int val;
        int x1 = 0;
        int x2 = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int index = std::abs(nums[i]) - 1;
            x2 ^= (i + 1);
            x1 ^= std::abs(nums[i]);
            
            if (nums[index] < 0) {
                val = index + 1;
            }
            
            nums[index] *= -1;
        }
        
        x2 ^= x1;
        x2 ^= val;

        return std::vector<int>{val, x2};
    }
};