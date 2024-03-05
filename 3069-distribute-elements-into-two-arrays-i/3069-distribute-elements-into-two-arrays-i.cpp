class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        std::vector<int> res(nums.size());
        
        int l = 0;
        int r = nums.size() - 1;
        
        res[0] = nums[0];
        res[nums.size() - 1] = nums[1];
        
        for (int i = 2; i < nums.size(); ++i) {
            if (res[l] > res[r]) {
                ++l;
                res[l] = nums[i];
            } else {
                --r;
                res[r] = nums[i];
            }
        }
        
        l = r;
        r = nums.size() - 1;
        
        while(l < r) {
            std::swap(res[l], res[r]);
            ++l;
            --r;
        }
        
        
        return res;
    }
};