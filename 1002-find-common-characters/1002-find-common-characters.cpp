class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        if (words.size() == 1) {
            return words;
        }
        
        std::vector<std::vector<int>> data(words.size(), std::vector<int>(26));
        for (size_t i = 0; i < words.size(); ++i) {
            const auto& word = words[i];
            
            for (char ch : word) {
                ++data[i][ch - 'a'];
            }
        }
        
        std::vector<std::string> res;
        res.reserve(words.size()*2);
        
        for (int k = 0; k < 26; ++k) {
            int min = data[0][k];
            
            for (size_t i = 1; i < words.size(); ++i) {
                min = std::min(min, data[i][k]);
            }
            
            if (min > 0) {
                std::string str(1, k + 'a');
                
                while (min > 0) {
                    res.push_back(str);
                    --min;
                }
            }
        }
        
        return res;
    }
};