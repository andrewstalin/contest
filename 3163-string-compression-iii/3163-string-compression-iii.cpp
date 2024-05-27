class Solution {
public:
    string compressedString(string word) {
        int index = 0;
        std::string res;
        res.reserve(word.size()*2);
        
        while (index < word.size()) {
            char ch = word[index];
            int count = 0;
            
            while (index < word.size() && count < 9 && word[index] == ch) {
                ++index;
                ++count;
            }
            
            res.append(std::to_string(count));
            res.push_back(ch);
        }
        
        return res;
    }
};