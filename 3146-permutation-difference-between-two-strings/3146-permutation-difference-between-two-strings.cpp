class Solution {
public:
    int findPermutationDifference(string s, string t) {
        std::vector<int> data(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            data[s[i] - 'a'] = i;
        }
        
        int res = 0;
        
        for (int i = 0; i < t.size(); ++i) {
            res += std::abs(i - data[t[i] - 'a']);
        }
        
        return res;
    }
};