class Solution {
public:
    int maximumLength(string s) {
        std::vector<std::vector<int>> data(26, std::vector<int>(s.size() + 1, 0));
        int k = 1;
        int count = 1;
        char ch = s[0];
        
        int res = 0;
        
        while (k < s.size()) {
            if (s[k] == ch) {
                ++count;
            } else {
                int index = ch - 'a';
                
                for (int i = count; i >= 1; --i) {
                    data[index][i] += count - i + 1;
                    
                    if (data[index][i] >= 3 && res < i) {
                        res = i;
                        break;
                    }
                }
                
                count = 1;
                ch = s[k];
            }
            
            ++k;
        }
        
        int index = ch - 'a';
                
        for (int i = count; i >= 1; --i) {
            data[index][i] += count - i + 1;
            
            if (data[index][i] >= 3 && res < i) {
                res = i;
                break;
            }
        }
        
        return res == 0 ? -1 : res;
    }
};