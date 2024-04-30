class Solution {
public:
    long long wonderfulSubstrings(string word) {
        std::vector<int> data(1024, 0);
        data[0] = 1;
        
        int index = 0;
        long long res = 0;
        
        for (int i = 0; i < word.size(); ++i) {
            index ^= (1 << (word[i] - 'a'));
            res += data[index];
            ++data[index];

            for (int k = 0; k < 10; ++k) {
                res += data[(index ^ (1 << k))];
            }
        }
        
        return res;
    }
};