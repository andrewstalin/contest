class Solution {
public:
    int calc(int val) {
        int res = 0;
        while (val > 0) {
            res += (val & 1);
            val >>= 1;
        }
        return res;
    }
    bool canSortArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        
        std::vector<int> bits(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            bits[i] = calc(nums[i]);
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            int k = i - 1;
            
            while (k >= 0 && nums[k] > nums[k + 1]) {
                if (bits[k] == bits[k + 1]) {
                    std::swap(bits[k], bits[k + 1]);
                    std::swap(nums[k], nums[k + 1]);
                    --k;
                    continue;
                }
                
                return false;
            }
        }
        
        return true;
    }
};