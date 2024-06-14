class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int res = 0;
        int count = 1;
        int prev = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == prev) {
                ++count;
                continue;
            }
            
            if (count > 1) {
                int min = std::min(count - 1, nums[i] - prev - 1);
                count -= min;
                res += ((1 + min)*min)/2;
                
                if (count > 1) {
                    res += (count - 1)*(nums[i] - prev);
                } else {
                    count = 1;
                }
            }
            
            prev = nums[i];
        }
        
        if (count > 1) {
            --count;
            res += ((1 + count)*count)/2;  
        }
        
        return res;
    }
    
    int minIncrementForUnique0(vector<int>& nums) {
        std::vector<int> data(200001, 0);
        for (int val : nums) {
            ++data[val];
        }
        
        int res = 0;
        
        for (size_t i = 0, end = data.size() - 1; i < end; ++i) {
            if (data[i] > 1) {
                res += data[i] - 1;
                data[i + 1] += data[i] - 1;
                data[i] = 1;
            }
        }
        
        return res;
    }
};