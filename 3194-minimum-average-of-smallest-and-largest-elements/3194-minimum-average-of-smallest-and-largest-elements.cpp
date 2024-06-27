class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        if (nums.size() == 2) {
            return static_cast<double>(nums[0] + nums[1])/2;
        }
        
        std::vector<int> data(51);
        for (int num : nums) {
            ++data[num];
        }
        
        int l = 0;
        int r = data.size() - 1;
        
        int min = INT32_MAX;
        
        while (l <= r) {
            if (data[l] == 0) {
                ++l;
                continue;
            }
            
            if (data[r] == 0) {
                --r;
                continue;
            }
            
            min = std::min(min, r + l);
            --data[r];
            --data[l];
        }
        
        
        return static_cast<double>(min)/2;
    }
};