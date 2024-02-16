class Solution {
public:

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); ++i) {
            ++map[arr[i]];
        }
        
        std::vector<int> data;
        data.reserve(map.size());
        
        for (auto it = map.begin(); it != map.end(); ++it) {
            data.emplace_back(it->second);
        }
        
        std::sort(data.begin(), data.end());
        int index = 0;
        
        while (index < data.size()) {
            if (data[index] > k) {
                break;
            }
            
            k -= data[index];
            ++index;
        }
        
        return data.size() - index;
    }
};