class Solution {
public:
    string reversePrefix(string word, char ch) {
        int r = -1;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                r = i;
                break;
            }
        }
        
        if (r != -1) {
            int l = 0;
            while (l < r) {
                std::swap(word[l], word[r]);
                ++l;
                --r;
            }
        }
        
        return word;
    }
};