class Solution {
public:
    
    int numberOfSpecialChars(string word) {
        std::vector<int> data(26, 0);
        int res = 0;
        int index;
        int shift;
        
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] >= 'a') {
                index = word[i] - 'a';
                shift = 0;        
            } else {
                index = word[i] - 'A';
                shift = 1;
            }
            
            if (data[index] == 3) {
                continue;
            }
            
            data[index] |= (1 << shift);
                
            if (data[index] == 3) {
                ++res;
            }
        }
        
        return res;
    }
};