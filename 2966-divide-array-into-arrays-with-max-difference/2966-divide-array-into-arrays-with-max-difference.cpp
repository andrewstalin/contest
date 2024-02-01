class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if (nums.size() % 3 != 0) {
            return std::vector<std::vector<int>>();
        }
        
        std::vector<std::vector<int>> res;
        res.reserve(nums.size() % 3);
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 1] - nums[i] > k || nums[i + 2] - nums[i] > k) {
                return std::vector<std::vector<int>>();
            }
            
            std::vector<int> item(3, 0);
            item[0] = nums[i];
            item[1] = nums[i + 1];
            item[2] = nums[i + 2];
            res.emplace_back(std::move(item));
        }
        
        return res;
    }
};