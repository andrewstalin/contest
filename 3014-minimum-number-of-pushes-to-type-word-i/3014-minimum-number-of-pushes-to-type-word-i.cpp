class Solution {
public:
    int minimumPushes(string word) {
        int count = word.size();
        int res = 0;
        int k = 1;
        
        while (count > 0) {
            res += count <= 8 ? k*count : 8*k;
            count -= 8;
            ++k;
        }
        
        return res;
    }
};