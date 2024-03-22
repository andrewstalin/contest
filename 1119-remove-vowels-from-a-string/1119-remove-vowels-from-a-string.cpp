class Solution {
public:
    
    string removeVowels(string s) {
        int l = 0;
        int r = 0;
        
        while (r < s.size()) {
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                ++r;
                continue;
            }
            
            std::swap(s[l], s[r]);
            ++l;
            ++r;
        }
        
        s.resize(l);
        return s;
    }
};