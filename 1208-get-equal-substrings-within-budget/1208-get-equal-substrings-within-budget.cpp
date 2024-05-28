class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0;
        int r = 0;
        int cost = 0;
        int res = 0;
        
        while (r < s.size()) {
            if (s[r] != t[r]) {
                cost += std::abs(s[r] - t[r]);
                
                while (l <  r && cost > maxCost) {
                    cost -= std::abs(s[l] - t[l]);
                    ++l;
                }
            }
            
            if (cost <= maxCost) {
                res = std::max(res, r - l + 1);
            }
            
            ++r;
        }
        
        return res;
    }
};