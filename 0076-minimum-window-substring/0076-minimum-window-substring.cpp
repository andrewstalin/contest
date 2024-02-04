class Solution {
public:
    inline int to_index(char ch) {
        return ch < 'a' ? (ch + 26 - 'A') : (ch - 'a');
    }
    
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        
        std::vector<int> pattern(52, 0);
        
        for (int i = 0; i < t.size(); ++i) {
            int index = to_index(t[i]);
            ++pattern[index];
        }
        
        int count = 0;
        int l = 0;
        int r = 0;
        int begin = -1;
        int size = INT32_MAX;
        
        std::vector<int> data(52, 0);
        
        while (r < s.size()) {
            int index = to_index(s[r]);
            ++data[index];
            
            if (pattern[index] > 0 && data[index] <= pattern[index]) {
                ++count;
            }
            
            while (count == t.size()) {
                if ((r - l + 1) < size) {
                    size = r - l + 1;
                    begin = l;
                }
                
                index = to_index(s[l]);
                --data[index];
                ++l;
                
                if (pattern[index] > 0 && data[index] < pattern[index]) {
                    --count;
                }
            }
            
            ++r;
        }
        
        return begin == -1 ? "" : s.substr(begin, size); 
    }
};