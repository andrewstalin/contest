
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int64_t sum = 0;
        int64_t res = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < sum) {
                res = nums[i] + sum;
            }
            
            sum += nums[i];
        }
        
        return res;
    }
};