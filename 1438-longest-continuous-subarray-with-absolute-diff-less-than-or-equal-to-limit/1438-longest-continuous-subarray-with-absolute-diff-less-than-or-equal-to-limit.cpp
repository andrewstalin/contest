class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        std::map<int, int> map;
        
        int l = 0;
        int r = 0;
        int res = 0;
        int size = 0;
        
        while (r < nums.size()) {
            ++map[nums[r]];
            ++size;
            
            while (true) {
                auto begin = map.begin();
                auto end = map.end();
                --end;
                
                if (std::abs(nums[r] - begin->first) <= limit
                    && std::abs(nums[r] - end->first) <= limit) {
                    break;
                }
                
                --size;
                auto it = map.find(nums[l]);
                
                if (--it->second == 0) {
                    map.erase(it);
                }
                
                ++l;
            }
            
            res = std::max(res, size);
            ++r;
        }
        
        return res;
    }
};