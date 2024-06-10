class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> data(heights.begin(), heights.end());
        
        std::sort(data.begin(), data.end());
        int res = 0;
        
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] != heights[i]) {
                ++res;
            }
        }
        
        return res;
    }
};