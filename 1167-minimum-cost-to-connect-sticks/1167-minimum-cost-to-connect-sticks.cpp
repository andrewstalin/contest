class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if (sticks.size() == 1) {
            return 0;
        }
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        int res = 0;
        
        for (int i = 0; i < sticks.size(); ++i) {
            queue.emplace(sticks[i]);
        }
        
        int v1, v2, v;
        
        while (queue.size() > 1) {
            v1 = queue.top();
            queue.pop();
            
            v2 = queue.top();
            queue.pop();
            
            v = v1 + v2;
            res += v;
            
            queue.emplace(v);
        }
        
        return res;
    }
};