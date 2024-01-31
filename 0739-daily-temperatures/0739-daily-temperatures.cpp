class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        
        std::stack<std::pair<int, int>> stack;
        stack.emplace(temperatures.back(), temperatures.size() - 1);
        
        for (int i = (temperatures.size() - 2); i >= 0; --i) {
            while (!stack.empty() && stack.top().first <= temperatures[i]) {
                stack.pop();
            }
            
            if (!stack.empty()) {
                res[i] = stack.top().second - i;
            }
            
            stack.emplace(temperatures[i], i);
        }
        
        return res;
    }
};