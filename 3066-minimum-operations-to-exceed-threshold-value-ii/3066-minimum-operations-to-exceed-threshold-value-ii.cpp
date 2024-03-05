class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> queue;
        for (const auto& num : nums) {
            queue.emplace(num);
        }
        
        uint64_t v1, v2;
        int res = 0;
        
        while(queue.size() >= 2 && queue.top() < k) {
            v1 = queue.top();
            queue.pop();
            
            v2 = queue.top();
            queue.pop();
            
            queue.emplace(std::min(v1, v2)*2 + std::max(v1, v2));
            ++res;
        }
        
        return res;
    }
};