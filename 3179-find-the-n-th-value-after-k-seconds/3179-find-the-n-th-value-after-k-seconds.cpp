class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        if (k == 1) {
            return n;
        }
        
        std::vector<int> data(n, 0);
        std::iota(data.begin(), data.end(), 1);
        std::vector<int> tmp(n, 0);
        
        for (int i = 2; i <= k; ++i) {
            tmp[0] = 1;
            
            for (int i = 1; i < n; ++i) {
                tmp[i] = data[i] + tmp[i - 1]; 
                tmp[i] %= 1000000007;
            }
            
            std::swap(tmp, data);
        }
        
        return data.back();
    }
};