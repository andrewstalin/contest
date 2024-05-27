class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        std::vector<int> res(queries.size(), -1);
        
        std::vector<int> data;
        data.reserve(nums.size());
        
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                data.push_back(i);
            }
        }
        
        for (size_t i = 0; i < queries.size(); ++i) {
            if (queries[i] > data.size()) {
                continue;
            }
            
            res[i] = data[queries[i] - 1];
        }
        
        return res;
    }
};