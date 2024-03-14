class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        std::unordered_map<int, int> map(nums.size());
        ++map[0];
        
        int res{ 0 };
        int sum{ 0 };
        
        for (const auto& num : nums) {
            sum += num;
            auto it = map.find(sum - goal);
            
            if (it != map.end()) {
                res += it->second;
            }
            
            ++map[sum];
        }
        
        return res;
    }
};