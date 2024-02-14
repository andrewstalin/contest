class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::vector<int> res(nums.size(), 0);
        int pos = 0;
        int neg = 0;
        int index = 0;
        
        while (index < nums.size()) {
            while (nums[pos] < 0) {
                ++pos;
            }
            
            while (nums[neg] > 0) {
                ++neg;
            }
            
            res[index++] = nums[pos++];
            res[index++] = nums[neg++];
        }
        
        return res;
    }
};