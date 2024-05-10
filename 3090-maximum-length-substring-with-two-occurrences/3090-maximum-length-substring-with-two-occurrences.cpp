class Solution {
public:
    int maximumLengthSubstring(string s) {
        std::vector<int> data(26, 0);
        int res = 0;
        int l = 0;
        int r = 0;
        
        while (r < s.size()) {
            if (++data[s[r] - 'a'] > 2) {
                res = std::max(res, r - l);
                
                while (l < r) {
                    if (--data[s[l] - 'a'] == 2) {
                        ++l;
                        break;
                    }
                    
                    ++l;
                }
            }
            
            ++r;
        }
        
        return std::max(res, r - l);
    }
};