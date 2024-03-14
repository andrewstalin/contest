class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res{ 0 };
        int l{ 0 };
        int r{ 0 };
        int sum{ 0 };
        
        while (r < nums.size()) {
            sum += nums[r];
            ++r;
            
            if (sum == goal) {
                int nextl = l;
                int nextr = r - 1;
                int tmp = sum;
                
                while (nextr < nums.size() && tmp == goal) {
                    ++nextr;
                    tmp += nums[nextr];
                }
                
                tmp = sum;
                
                while (nextl < nextr && sum == goal) {
                    sum -= nums[nextl];
                    ++nextl;
                }
                
                res += nextl == nextr ? (nextl - l + 1)*(nextl - l)/2 : (nextl - l)*(nextr - r + 1);
                l = nextl;
                r = nextr;
            } else if (sum > goal) {
                sum -= nums[l];
                ++l;
            }
        }
        
        return res;
    }
    
    int numSubarraysWithSum0(vector<int>& nums, int goal) {
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