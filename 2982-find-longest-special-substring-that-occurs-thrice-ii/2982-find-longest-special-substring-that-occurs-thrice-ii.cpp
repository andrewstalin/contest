class Solution {
public:
    int maximumLength(string s) {
        std::vector<std::vector<int>> data(26, std::vector<int>(s.size() + 1, 0));
        int k = 1;
        int count = 1;
        char ch = s[0];
        
        while (k < s.size()) {
            if (s[k] == ch) {
                ++count;
            } else {
                int index = ch - 'a';
                
                for (int i = 1; i <= count; ++i) {
                    data[index][i] += count - i + 1;
                }
                
                count = 1;
                ch = s[k];
            }
            
            ++k;
        }
        
        int index = ch - 'a';
                
        for (int i = 1; i <= count; ++i) {
            data[index][i] += count - i + 1;
        }
        
        int res = 0;
        
        for (int i = 0; i < 26; ++i) {
            for (int j = s.size(); j > 0; --j) {
                if (data[i][j] >= 3) {
                    res = std::max(res, j);
                    break;
                }
            }
        }
        
        return res == 0 ? -1 : res;
    }
};