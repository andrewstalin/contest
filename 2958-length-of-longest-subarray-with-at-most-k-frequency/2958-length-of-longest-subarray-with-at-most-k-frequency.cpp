class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::unordered_map<int, int> map(nums.size());
        int l = 0;
        int r = 0;
        int res = 0;
        int count = 0;
        
        while (r < nums.size()) {
            if (++map[nums[r]] > k) {
                res = std::max(res, count);
                
                while (l < r) {
                    --map[nums[l]];
                    --count;
                    
                    if (nums[l] == nums[r]) {
                        ++l;
                        break;
                    }
                    
                    ++l;
                }
            }
            
            ++count;
            ++r;
        }
        
        return std::max(res, count);
    }
};