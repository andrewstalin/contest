class Solution {
public:
    inline int to_index(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 26;
        } else {
            return ch - '0' + 52;
        }
    }
    
    inline char to_char(int index) {
        if (index < 26) {
            return index + 'a';
        } else if (index < 52) {
            return index + 'A' - 26;
        } else {
            return index + '0' - 52;
        }
    }
    
    string frequencySort(string s) {
        std::vector<std::pair<int, char>> chars;
        chars.reserve(62);
        
        for (int i = 0; i < 62; ++i) {
            chars.emplace_back(0, to_char(i));
        }
        
        for (int i = 0; i < s.size(); ++i) {
            ++chars[to_index(s[i])].first;
        }
        
        std::sort(chars.begin(), chars.end(), [](const std::pair<int, char>& p1, const std::pair<int, char>& p2){
            return p1.first != p2.first ? p1.first > p2.first : p1.second < p2.second;
        });
        
        int pos = 0;
        
        for (int i = 0; i < chars.size(); ++i) {
            while (chars[i].first > 0) {
                --chars[i].first;
                s[pos] = chars[i].second;
                ++pos;
            }
        }
        
        return s;
    }
};