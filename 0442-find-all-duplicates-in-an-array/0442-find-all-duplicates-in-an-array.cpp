class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> res(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            ++res[nums[i] - 1];
        }
        
        int l = -1;
        int r = 0;
        
        while (r < res.size()) {
            if (res[r] == 2) {
                ++l;
                res[l] = r + 1;
            }
            
            ++r;
        }

        res.resize(l + 1);
        return res;
    }
};