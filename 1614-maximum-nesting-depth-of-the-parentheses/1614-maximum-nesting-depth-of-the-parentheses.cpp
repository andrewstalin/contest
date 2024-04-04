class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++count;
            } else if (s[i] == ')') {
                res = std::max(res, count);
                --count;
            }
        }
        return std::max(res, count);
    }
};