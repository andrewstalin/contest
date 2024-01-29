class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> map;
        int begin = 0;
        int end = 0;
        int res = 0;
        
        while (end < s.size()) {
            if (++map[s[end]] > 1) {
                char ch = s[end];
                
                while (s[begin] != ch) {
                    --map[s[begin]];
                    ++begin;
                }
                --map[ch];
                ++begin;
            } else {
                res = std::max(res, end - begin + 1);
            }
            
            ++end;
        }
        
        return std::max(res, end - begin);
    }
};