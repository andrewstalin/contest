class Solution {
public:
    bool func(int pattern_pos, const std::string& pattern, int s_pos, const std::string& s, std::vector<std::pair<int, int>>& chars, std::unordered_set<std::string_view>& set) {
        if (pattern_pos >= pattern.size()) {
            return s_pos >= s.size();
        }
        
        auto& pattern_item = chars[pattern[pattern_pos] - 'a'];
        
        if (pattern_item.first != -1) {
            if (pattern_item.second > s.size() - s_pos) {
                return false;
            }
            
            for (int i = pattern_item.first, j = s_pos, end = pattern_item.first + pattern_item.second; i < end; ++i, ++j) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            
            return func(pattern_pos + 1, pattern, s_pos + pattern_item.second, s, chars, set);
        }
        
        pattern_item.first = s_pos;
        pattern_item.second = 1;
        int next = pattern_pos + 1;
        
        for (int i = s_pos, end = s.size() - pattern.size() + pattern_pos + 1; i < end; ++i) {
            auto it = set.emplace(s.data() + s_pos, pattern_item.second);
            
            if (!it.second) {
                ++pattern_item.second;
                continue;
            }
            
            if (func(next, pattern, s_pos + pattern_item.second, s, chars, set)) {
                return true;
            }
            
            set.erase(it.first);
           ++pattern_item.second;
        }
        
        pattern_item.first = -1;
        pattern_item.second = -1;
        return false;
    }
        
    bool wordPatternMatch(string pattern, string s) {
        std::vector<std::pair<int, int>> chars(26, std::make_pair(-1, -1));
        std::unordered_set<std::string_view> set;
        return func(0, pattern, 0, s, chars, set);
        
    }
};