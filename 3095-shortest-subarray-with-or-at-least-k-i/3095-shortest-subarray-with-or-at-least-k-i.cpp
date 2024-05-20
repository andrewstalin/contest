class Solution {
public:
    void add(int val, std::vector<int>& bits) {
        int index = 0;
        
        while(val > 0) {
            if ((val & 1) == 1) {
                ++bits[index];
            }
            ++index;
            val >>= 1;
        }    
    }
    
    int subtract(int total, int val, std::vector<int>& bits) {
        int index = 0;
        
        while(val > 0) {
            if ((val & 1) == 1) {
                if (--bits[index] == 0) {
                    total ^= (1 << index);
                }
            }
            ++index;
            val >>= 1;
        }
        return total;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int res = INT32_MAX;
        int total = 0;
        
        std::vector<int> bits(32, 0);
        
        while (r < nums.size()) {
            total |= nums[r];
            add(nums[r], bits);
            
            while (total >= k && l <= r) {
                res = std::min(res, r - l + 1);
                total = subtract(total, nums[l], bits);
                ++l;
            }
            
            ++r;
        }
        
        return res == INT32_MAX ? -1 : res;
    }
};