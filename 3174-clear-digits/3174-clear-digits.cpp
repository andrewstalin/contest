class Solution {
public:
    string clearDigits(string s) {
        std::stack<char> stack;
        
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                stack.push(s[i]);
            }
        }
        
        if (stack.empty()) {
            return "";
        }
        
        s.resize(stack.size());
        
        for (size_t i = stack.size() - 1; !stack.empty(); --i) {
            s[i] = stack.top();
            stack.pop();
        }
        
        return s;
    }
};