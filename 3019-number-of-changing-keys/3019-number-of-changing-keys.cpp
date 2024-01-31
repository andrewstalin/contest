class Solution {
public:
    int countKeyChanges(string s) {
        int res = 0;
        int prev = s[0] - (s[0] < 'a' ? 'A' : 'a');
        
        for (int i = 1; i < s.size(); ++i) {
            int k = s[i] - (s[i] < 'a' ? 'A' : 'a');
            
            if (prev != k) {
                ++res;
            }
            
            prev = k;
        }
        
        return res;
    }
};