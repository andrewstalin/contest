class Solution {
public:
    int minimumChairs(string s) {
        int res = 0;
        int count = 0;
        
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == 'E') {
                ++count;
                res = std::max(res, count);
            } else {
                --count;
            }
        }
        
        return res;
    }
};