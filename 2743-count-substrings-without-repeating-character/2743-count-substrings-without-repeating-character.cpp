class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        std::vector<int> data(26, 0);
        size_t l = 0;
        size_t r = 0;
        int res = 0;
        int prev = -1;
        
        while (r < s.size()) {
            if (++data[s[r] - 'a'] > 1) {
                int size = r - l;
                res += ((1 + size)*size)/2;
                
                if (l < prev) {
                    size = prev - l;
                    res -= ((1 + size)*size)/2;
                }
                
                prev = r;
                
                while (s[l] != s[r]) {
                    --data[s[l] - 'a'];
                    ++l;
                }
                
                --data[s[l] - 'a'];
                ++l;
            }
            
            ++r;
        }
        
        int size = r - l;
        res += ((1 + size)*size)/2;
        
        if (l < prev) {
            size = prev - l;
            res -= ((1 + size)*size)/2;
        }
        
        return res;
    }
};