class Solution {
public:
    inline int get_index(char ch) {
        return ch >= 'a' ? (ch - 'a') : (ch - 'A' + 26);
    }
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        std::vector<int> data(52, 0);
        int l = 0;
        int r = 0;
        int count = 0;
        int res = 0;
        
        while (r < s.size()) {
            if (++data[get_index(s[r])] == 1) {
                ++count;
                
                if (count > 2) {
                    res = std::max(res, r - l);

                    while (count > 2) {
                        if (--data[get_index(s[l])] == 0) {
                            --count;
                        }
                        
                        ++l;
                    }
                }
            }
            
            ++r;
        }
        
        return std::max(res, r - l);
    }
};