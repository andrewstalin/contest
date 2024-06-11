class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::vector<int> index(1001, INT32_MAX);
        for (int i = 0; i < arr2.size(); ++i) {
            index[arr2[i]] = i;
        }
        
        std::sort(arr1.begin(), arr1.end(), [&index](int i1, int i2){
            if (index[i1] != INT32_MAX && index[i2] != INT32_MAX) {
                return index[i1] < index[i2];
            } else if (index[i1] == INT32_MAX && index[i2] == INT32_MAX) {
                return i1 < i2;
            } else {
                return index[i1] != INT32_MAX;  
            }
        });
        
        return arr1;
    }
};