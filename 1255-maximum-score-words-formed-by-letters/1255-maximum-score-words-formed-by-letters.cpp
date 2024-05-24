
class Solution {
public:
    int func(int pos, const std::vector<std::string>& words, const std::vector<int>& scores, std::vector<int>& letters) {
        if (pos >= words.size()) {
            return 0;
        }
        
        int val1 = func(pos + 1, words, scores, letters);  
        int val2 = 0;
        int index = 0;
        int k;
        
        while (index < words[pos].size()) {
            k = words[pos][index] - 'a';
            
            if (letters[k] == 0) {
                --index;
                while (index >= 0) {
                    k = words[pos][index] - 'a';
                    ++letters[k];
                    --index;
                }
                
                val2 = 0;
                break;
            }
            
            val2 += scores[k];
            --letters[k];
            ++index;
        }
        
        if (val2 > 0) {
            val2 += func(pos + 1, words, scores, letters);
            
            for(char ch : words[pos]) {
                ++letters[ch - 'a'];
            }
        }
        
        return std::max(val1, val2);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        std::vector<int> chars(26, 0);
        for (char ch : letters) {
            ++chars[ch - 'a'];
        }
        return func(0, words, score, chars);
    }
};


/*

["daeagfh","acchggghfg","feggd","fhdch","dbgadcchfg","b","db","fgchfe","baaedddc"]
["a","a","a","a","a","a","a","b","b","b","b","b","b","b","b","b","c","c","c","c","c","c","c","c","c","c","c","d","d","d","d","d","d","d","d","d","d","d","d","d","d","e","e","e","e","e","e","e","e","e","e","f","f","f","f","f","f","f","f","f","f","f","f","f","f","g","g","g","g","g","g","g","g","g","g","g","g","h","h","h","h","h","h","h","h","h","h","h","h","h"]
[2,1,9,2,10,5,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
["dog","cat","dad","good"]
["a","a","c","d","d","d","g","o","o"]
[1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
["xxxz","ax","bx","cx"]
["z","a","b","c","x","x","x"]
[4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
["leetcode"]
["l","e","t","c","o","d"]
[0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
["add","dda","bb","ba","add"]
["a","a","a","a","b","b","b","b","c","c","c","c","c","d","d","d"]
[3,9,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
["e","bac","baeba","eb","bbbbd","cad","c","c"]
["a","a","a","a","a","a","a","b","b","b","b","b","b","c","c","c","c","c","c","d","d","d","d","d","d","d","e","e","e","e"]
[8,4,6,8,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
["ad","dbacbbedc","ae","adbdacad","dcdecacdcb","ddbba","dbcdbeaade","aeccdcb","bce"]
["a","a","a","a","a","a","a","a","a","a","a","a","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","c","c","c","c","c","c","c","c","c","c","d","d","d","d","e","e","e","e","e","e"]
[1,8,3,1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

*/
