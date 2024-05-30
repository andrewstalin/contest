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
};