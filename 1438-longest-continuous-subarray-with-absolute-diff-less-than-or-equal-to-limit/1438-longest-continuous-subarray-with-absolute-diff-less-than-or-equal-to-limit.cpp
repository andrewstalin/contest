class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::deque<int> max;
        max.emplace_back(nums[0]);
        
        std::deque<int> min;
        min.emplace_back(nums[0]);
        
        int res = 1;
        int l = 0;
        int r = 1;
        
        while (r < nums.size()) {
            while (!max.empty() && max.back() < nums[r]) {
                max.pop_back();
            }
            max.emplace_back(nums[r]);
            
            while (!min.empty() && min.back() > nums[r]) {
                min.pop_back();
            }
            min.emplace_back(nums[r]);
            
            while (std::abs(max.front() - min.front()) > limit) {
                if (max.front() == nums[l]) {
                    max.pop_front();
                }
                
                if (min.front() == nums[l]) {
                    min.pop_front();
                }
                
                ++l;
            }
            
            res = std::max(res, r - l + 1);
            ++r;
        }
        
        return res;
    }
    
    int longestSubarray0(vector<int>& nums, int limit) {

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