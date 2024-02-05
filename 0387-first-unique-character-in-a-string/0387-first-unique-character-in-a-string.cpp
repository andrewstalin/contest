class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<int> letters(26, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            ++letters[s[i] - 'a'];
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (letters[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};