class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        
        int res = 0;
        
        std::vector<int> data(256, 0);
        int l = 0;
        int r = 0;
        int count = 0;
        
        while (r < s.size()) {
            if (++data[s[r]] == 1) {
                ++count;
            }
            
            if (count > k) {
                res = std::max(res, r - l);
                
                while (l < r) {
                    if (--data[s[l]] == 0) {
                        --count;
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