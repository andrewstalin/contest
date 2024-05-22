
class Solution {
public:
    
    void func(int l, int pos, const std::string& s, std::vector<std::pair<int, int>>& items, std::vector<std::vector<std::string>>& res) {
        if (l >= s.size()) {
            std::vector<std::string> palindromes;
            palindromes.reserve(items.size());
            
            for (const auto& item : items) {
                palindromes.emplace_back(s.substr(item.first, item.second));
            }
            
            res.emplace_back(std::move(palindromes));
            return;
        }
        
        if (pos >= s.size()) {
            return;
        }
        
        bool palindrome = true;
        
        for (int i = l, j = pos; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                palindrome = false;
                break;
            }
        }
        
        if (palindrome) {
            items.emplace_back(l, pos - l + 1);
            func(pos + 1, pos + 1, s, items, res);
            items.resize(items.size() - 1);
        }
        
        func(l, pos + 1, s, items, res);
    }
    
        
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> res;
        
        std::vector<std::pair<int, int>> items;
        items.reserve(s.size());
        
        func(0, 0, s, items, res);
        
        return res;
    }
};