class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        int add = 0;
        int index = s.size() - 1;
        
        while (index > 0) {
            if (add > 0) {
                if (add == 1) {
                    add = s[index] == '1' ? 1 : 0;
                    s[index] = s[index] == '1' ? '0' : '1';
                } else {
                    if (add % 2 != 0) {
                        s[index] = s[index] == '1' ? '0' : '1';
                    }

                    add /= 2;
                }
            }
            
            if (s[index] == '1') {
                ++res;
                ++add;
            }
            
            --index;
            ++res;
        }
        
        int val = s[0] - '0';
        while (add > 0) {
            if (add % 2 != 0) {
                val = val == 1 ? 0 : 1;
            }
            
            if (val == 1) {
                ++add;
            }
            
            add /= 2;
            ++res;
        } 
        
        return res;
    }
};