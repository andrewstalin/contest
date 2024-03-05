class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            char ch = s[l];
            
            if (s[l] != s[r]) {
                break;
            }
            
            while(l < r && s[l] == ch) {
                ++l;
            }
            
            while (l <= r && s[r] == ch) {
                --r;
            }
        }
        
        return r < l ? 0 : r - l + 1;
    }
};