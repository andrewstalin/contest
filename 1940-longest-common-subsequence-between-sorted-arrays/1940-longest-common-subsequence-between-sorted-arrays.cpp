class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        std::vector<int> res;
        res.reserve(100);
        
        std::vector<int> index(arrays.size());
        bool not_done = true;
        int val = arrays[0][0];
        
        while (not_done){
            int max = val;
            val = max;
            
            for (size_t i = 0; i < arrays.size(); ++i) {
                while (index[i] < arrays[i].size() && arrays[i][index[i]] < max) {
                    ++index[i];
                }
                
                if (index[i] >= arrays[i].size()) {
                    not_done = false;
                    break;
                }
                
                val = std::max(val, arrays[i][index[i]]);
            }
            
            if (not_done && max == val) {
                res.emplace_back(val);
                
                for (size_t i = 0; i < arrays.size(); ++i) {
                    not_done = not_done && (++index[i] < arrays[i].size());
                }
            }
        }
        
        return res;
    }
};