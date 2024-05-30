class Solution {
public:
    int countTriplets(vector<int>& arr) { 
        int res = 0;
        for (size_t i = 0; i < (arr.size() - 1); ++i) {
            int val = arr[i];

            for (size_t j = i + 1; j < arr.size(); ++j) {
                val ^= arr[j];
                
                if (val == 0) {
                    res += (j - i);    
                }
            }
        }
        return res;
    }
    
    int countTriplets0(vector<int>& arr) {       
        std::vector<std::unordered_map<int, int>> map(arr.size());
        
        for (size_t i = 1; i < arr.size(); ++i) {
            int val = 0;
            
            for (size_t j = i; j < arr.size(); ++j) {
                val ^= arr[j];
                ++map[i][val];
            }
        }
        
        int res = 0;
        
        for (size_t i = 0; i < arr.size(); ++i) {
            int val = 0;
            
            for (size_t j = i; j < (arr.size() - 1); ++j) {
                val ^= arr[j];
                res += map[j + 1][val];
            }
        }
        
        return res;
    }
};