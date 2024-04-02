class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::vector<int> data1(256, -1);
        std::vector<int> data2(256, -1);
        
        for (int i = 0; i < s.size(); ++i) {
            if (data1[s[i]] == -1) {
                if (data2[t[i]] != -1) {
                    return false;
                }
                
                data1[s[i]] = t[i];
                data2[t[i]] = s[i];
                continue;
            }
            
            if (data1[s[i]] != t[i] || data2[t[i]] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};