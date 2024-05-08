class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::vector<std::string> res(score.size(), "");
        
        int max = score[0];
        for (size_t i = 1; i < score.size(); ++i) {
            max = std::max(max, score[i]);
        }
        
        std::vector<int> data(max + 1, -1);
        for (size_t i = 0; i < score.size(); ++i) {
            data[score[i]] = i;
        }
        
        int place = 0;
        
        for (int i = (data.size() - 1); i >= 0; --i) {
            if (data[i] < 0) {
                continue;
            }
            
            ++place;
            
            if (place < 4) {
                if (place == 1) {
                    res[data[i]] = "Gold Medal";
                } else if (place == 2) {
                    res[data[i]] = "Silver Medal";
                } else {
                    res[data[i]] = "Bronze Medal";
                }
            } else {
                res[data[i]] = std::to_string(place);
            }
        }
        
        return res;
    }
};