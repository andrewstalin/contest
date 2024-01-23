class Solution {
public:

    
    
    int maxLength(vector<string>& arr) {
        std::vector<int> mask(arr.size(), 0);
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[i].size(); ++j) {
                int k = (1 << (arr[i][j] - 'a'));
                
                if ((mask[i] & k) != 0) {
                    mask[i] = INT32_MAX;
                    break;
                }
                
                mask[i] |= k;
            }
        }
        
        int res = 0;
        int max = (1 << arr.size());
        for (int i = 1; i < max; ++i) {
            int k = i;
            int m = 0;
            int count = 0;
            
            for (int j = 0; j < arr.size() && k > 0; ++j) {
                if ((k & 1) != 0) {
                    if (mask[j] == INT32_MAX || ((m & mask[j]) != 0)) {
                        count = 0;
                        break;
                    }
                    
                    m |= mask[j];
                    count += arr[j].size();
                }
                
                k >>= 1;
            }
            
            res = std::max(res, count);
        }
        
        return res;
    }
};