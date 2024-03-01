class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int l = 0;
        int r = 0;
        
        while (r < s.size()) {
            if (s[r] == '1') {
                std::swap(s[l], s[r]);
                ++l;
            }
            
            ++r;
        }
        
        if (l > 0) {
            --l;
        }
        
        std::swap(s[l], s[s.size() - 1]);
        return s;
    }
};