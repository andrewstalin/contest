class Solution {
public:
    bool check_all(int val, const std::vector<int>& nums) {
        for (const auto& num : nums) {
            if (num % val != 0) {
                return false;
            }
        }
        return true;
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        
        std::unordered_map<int, std::vector<int>> map;
        std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 0};
    
        std::vector<std::vector<int>> data(nums.size());
        
        int val;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                return false;
            }
            
            int k = 0;
            val = nums[i];
            auto index = &map[primes[0]];
            int end = primes.size() - 1;
            
            while (k < end && val != 1) {
                if (val % primes[k] == 0) {
                    if (index->empty() || index->back() != i) {
                        index->emplace_back(i);
                        data[i].emplace_back(primes[k]);
                    }
                    
                    val /= primes[k];
                    continue;
                }
                
                ++k;
                index = &map[primes[k]];
            }
            
            if (val == nums[i]) {
                return check_all(nums[i], nums);
            }
        }
        
        std::vector<bool> visited(nums.size(), false);
        visited[0] = true;
        int remain = nums.size() - 1;
        
        std::queue<int> queue;
        queue.emplace(0);
        
        while (!queue.empty()) {
            auto k = queue.front();
            queue.pop();
            
            for (int i = 0; i < data[k].size() && remain > 0; ++i) {
                const auto& p = map[data[k][i]];
                
                for (int j = 0; j < p.size() && remain > 0; ++j) {
                    if (!visited[p[j]]) {
                        visited[p[j]] = true;
                        --remain;
                        queue.emplace(p[j]);
                    }
                }
            }
        }
        
        return remain == 0;
    }
};