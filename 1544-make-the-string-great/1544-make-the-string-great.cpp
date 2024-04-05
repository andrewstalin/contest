class Solution {
public:
    bool isBad(char ch1, char ch2) {
        return (ch1 >= 'a' && ch2 < 'a' && ch1 == (ch2 + 'a' - 'A'))
            || (ch2 >= 'a' && ch1 < 'a' && ch2 == (ch1 + 'a' - 'A')); 
    }
    
    string makeGood(string s) {
        std::stack<char> stack;
        int index = 0;
        
        while (index < (s.size() - 1)) {
            if (isBad(s[index], s[index + 1])) {
                index += 2;
                
                while (index < s.size() && !stack.empty() && isBad(stack.top(), s[index])) {
                    ++index;
                    stack.pop();
                }
            } else {
                stack.push(s[index]);
                ++index;
                    
            }
        }
        
        if (index < s.size()) {
            stack.push(s[index]);
        }
        
        std::string res(stack.size(), ' ');
        index = stack.size() - 1;
        
        while(!stack.empty()) {
            res[index] = stack.top();
            stack.pop();
            --index;
        }
        
        return res;
    }
};