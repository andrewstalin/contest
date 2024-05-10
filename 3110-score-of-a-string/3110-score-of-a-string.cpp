class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        
        for (size_t i = 0, end = s.size() - 1; i < end; ++i) {
            res += std::abs(s[i] - s[i + 1]);
        }
        
        return res;
    }
};