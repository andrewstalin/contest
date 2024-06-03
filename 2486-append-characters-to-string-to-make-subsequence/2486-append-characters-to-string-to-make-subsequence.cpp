class Solution {
public:
    int appendCharacters(string s, string t) {
        size_t pos1 = 0;
        size_t pos2 = 0;
        
       while (pos1 < s.size() && pos2 < t.size()) {
           if (s[pos1] == t[pos2]) {
               ++pos2;
           }
           
           ++pos1;
       }
        
        return t.size() - pos2;
    }
};