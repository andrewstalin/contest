class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res = 0;
        std::vector<bool> data(51, false);
        
        for (int v : nums) {
            if (data[v]) {
                res ^= v;
            }
            
            data[v] = true;
        }
        
        
        return res;
    }
};