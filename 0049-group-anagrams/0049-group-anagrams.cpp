class Solution {
public:

    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<uint32_t, std::vector<std::string>> map;
        std::vector<uint32_t> data(26, 0);
        
        for (int i = 0; i < strs.size(); ++i) {
            const auto& str = strs[i];
            
            for (int j = 0; j < str.size(); ++j) {
                ++data[str[j] - 'a'];
            }
            
            uint32_t hash = 0;
            for (int j = 0; j < 26; ++j) {
                hash ^= data[j] + 0x9e3779b9 + (hash << 6) + (hash >> 2);
                data[j] = 0;
            }
            
            map[hash].emplace_back(std::move(strs[i]));
        }
        
        std::vector<std::vector<std::string>> res;
        res.reserve(map.size());
        
        for (auto it = map.begin(); it != map.end(); ++it) {
            res.emplace_back(std::move(it->second));
        }
        
        return res;
    }
};