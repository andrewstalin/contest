class Solution {
public:
    inline int encrypt(int val) {
        int max = 0;
        int count = 0;
        
        while(val > 0) {
            max = std::max(max, val%10);
            val /= 10;
            ++count;
        }
        
        int res = 0;
        while(count > 0) {
            res *= 10;
            res += max;
            --count;
        }
        
        return res;
    }
    
    int sumOfEncryptedInt(vector<int>& nums) {
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            res += encrypt(nums[i]);
        }
        
        return res;
    }
};