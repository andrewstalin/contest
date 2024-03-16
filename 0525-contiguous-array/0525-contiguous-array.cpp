class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> map;
        int sum = 0;
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1);
            
            if (sum == 0) {
                res = std::max(res, i + 1);
                continue;
            }
            
            auto it = map.find(sum);
            if (it != map.end()) {
                res = std::max(res, i - it->second);
            } else {
                map[sum] = i;   
            }
        }
        
        return res;
    }
};