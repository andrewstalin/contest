class Solution {
public:
    void func(int remain, int nums_pos, int item_pos, std::vector<int>& item, const std::vector<int>& nums, std::vector<std::vector<int>>& res) {
        if (nums.size() - nums_pos == remain) {
            auto val = item;
            while (nums_pos < nums.size()) {
                val[item_pos] = nums[nums_pos];
                ++item_pos;
                ++nums_pos;
            }
            res.emplace_back(std::move(val));
            return;
        }
        
        func(remain, nums_pos + 1, item_pos, item, nums, res);
        item[item_pos] = nums[nums_pos];
        
        if (remain == 1) {
            res.push_back(item);
            return;
        }
        
        func(remain - 1, nums_pos + 1, item_pos + 1, item, nums, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        res.reserve(std::pow(2, 10));
        
        res.emplace_back(std::vector<int>{});
        
        for (size_t i = 1; i < nums.size(); ++i) {
            std::vector<int> item(i);
            func(i, 0, 0, item, nums, res);
        }
        
        res.emplace_back(nums);
        return res;
    }
};