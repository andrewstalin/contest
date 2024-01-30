class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        
        for (int i = 0; i < tokens.size(); ++i) {
            const auto& token = tokens[i];
            
            if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                int v1 = stack.top();
                stack.pop();
                
                int v2 = stack.top();
                stack.pop();
                
                if (token[0] == '+') {
                    stack.emplace(v1 + v2);
                } else if (token[0] == '-') {
                    stack.emplace(v2 - v1);
                } else if (token[0] == '*') {
                    stack.emplace(v1*v2);
                } else {
                    stack.emplace(v2/v1);
                }
            } else {
                stack.emplace(std::stoi(token));
            }
        }
        
        return stack.top();
    }
};