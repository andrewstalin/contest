class Solution {
public:
    long long numberOfSubstrings(string s) {
        std::vector<int> data(26, 0);
        for (size_t i = 0; i < s.size(); ++i) {
            ++data[s[i] - 'a'];
        }
        
        long long res = 0;
        
        for (size_t i = 0; i < 26; ++i) {
            if (data[i] == 0) {
                continue;
            }
            
            long long val = data[i];
            res += (val + val*val)/2;
        }
        
        return res;
    }
};