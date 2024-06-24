class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        std::vector<char> data(nums.size(), 0);
        int a = 0;
        int res = 0;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            a += data[i];
            int val = (nums[i] + (a % 2))%2;
            
            if (val == 0) {
                ++a;
                ++res;
                
                int next = i + k;
                
                if (next > nums.size()) {
                    return -1;
                }
                
                if (next < nums.size()) {
                    data[next] = -1;
                }
            }
        }
        
        return res;
    }
};