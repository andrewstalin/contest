class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() == 1) {
            return 1;
        }

        
        std::vector<int> data(52, 0);
        for (size_t i = 0; i < s.size(); ++i) {
            ++data[s[i] <= 'Z' ? (s[i] - 'A' + 26) : (s[i] - 'a')];
        }
        
        int res = 0;
        bool odd = false;
        
        for (size_t i = 0; i < 52; ++i) {
            res += (data[i] / 2)*2;
            odd |= data[i] % 2 != 0;
        }
        
        return res + (odd ? 1 : 0);
    }
};