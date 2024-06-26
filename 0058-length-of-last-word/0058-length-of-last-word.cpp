class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        
        while (end >= 0 && s[end] == ' ') {
            --end;
        }
        
        if (end < 0) {
            return 0;
        }
        
        int begin = end;
        
        while (begin >= 0 && s[begin] != ' ') {
            --begin;
        }
        
        return end - begin;
    }
};