class Solution {
public:
    string lastNonEmptyString(string s) {
        std::vector<int> chars(26, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            ++chars[s[i] - 'a'];
        }
        
        int max = chars[0];
        int count = 1;
        
        for (int i = 1; i < 26; ++i) {
            if (max < chars[i]) {
                max = chars[i];
                count = 1;
            } else if(max == chars[i]) {
                ++count;
            }
        }
        
        std::string res;
        for (int i = (s.size() - 1); i >= 0 && count > 0; --i) {
            if (chars[s[i] - 'a'] == max) {
                res.push_back(s[i]);
                --count;
                chars[s[i] - 'a'] = 0;
            }
        }
        
        std::reverse(res.begin(), res.end());
        return res;
    }
};