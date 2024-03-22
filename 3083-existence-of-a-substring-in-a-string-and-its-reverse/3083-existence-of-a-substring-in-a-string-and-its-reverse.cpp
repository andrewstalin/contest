class Solution {
public:
    bool isSubstringPresent(string s) {
        if (s.size() < 2) {
            return false;
        }
        
        std::vector<std::vector<bool>> data(26, std::vector<bool>(26, false));
        
        for (int i = 0, end = s.size() - 1; i < end; ++i) {
            data[s[i] - 'a'][s[i + 1] - 'a'] = true;
        }
        
        std::reverse(s.begin(), s.end());
        for (int i = 0, end = s.size() - 1; i < end; ++i) {
            if (data[s[i] - 'a'][s[i + 1] - 'a']) {
                return true;
            }
        }
        
        return false;
    }
};