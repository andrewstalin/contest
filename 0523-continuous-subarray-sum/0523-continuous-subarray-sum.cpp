class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sum %= k;
            auto it = map.find(sum);
            
            if (it != map.end()) {
                if (i - it->second > 1) {
                    return true;
                }
            } else {
                map.emplace(sum, i);
            }
        }
        
        return false;
    }
};