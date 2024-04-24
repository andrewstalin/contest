class Solution {
public:
    int tribonacci(int n) {
        int nums[3] = {0, 1, 1};
        
        if (n < 3) {
            return nums[n];
        }
        
        int tmp;
        
        while (n >= 3) {
            tmp = nums[0] + nums[1] + nums[2];
            std::swap(nums[0], nums[1]);
            std::swap(nums[1], nums[2]);
            nums[2] = tmp;
            --n;
        }
        
        return nums[2];
    }
};