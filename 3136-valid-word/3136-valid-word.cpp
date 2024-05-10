class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        int val = 0;
        
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] == '@' || word[i] == '#' || word[i] == '$') {
                return false;
            }
            
        
            if (word[i] >= '0' && word[i] <= '9') {
                continue;
            }
            
            char ch = word[i];
            
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';
            }
            
            val |= (1 << (ch == 'a' || ch == 'e'  || ch == 'i' || ch == 'o' || ch == 'u' ? 0 : 1));
        }
        
        return val == 3;
    }
};