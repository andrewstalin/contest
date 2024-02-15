class Solution {
public:

    
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        std::vector<std::vector<int>> res;
        res.reserve(intervals.size());
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (toBeRemoved[0] == intervals[i][0] && toBeRemoved[1] == intervals[i][1]) {
                continue;
            }
            
            if (intervals[i][1] < toBeRemoved[0] || intervals[i][0] > toBeRemoved[1]) {
                res.emplace_back(std::move(intervals[i]));
            } else if ((toBeRemoved[0] <= intervals[i][0] && toBeRemoved[1] <= intervals[i][1])
                    || (toBeRemoved[0] >= intervals[i][0] && toBeRemoved[1] >= intervals[i][1])) {
                if (toBeRemoved[0] > intervals[i][0]) {
                    res.emplace_back(std::vector<int>{ intervals[i][0], toBeRemoved[0] });
                } else {
                    res.emplace_back(std::vector<int>{ toBeRemoved[1], intervals[i][1] });
                }
            } else if (toBeRemoved[0] > intervals[i][0] && toBeRemoved[0] < intervals[i][1] 
                        && toBeRemoved[1] > intervals[i][0] && toBeRemoved[1] < intervals[i][1]) {
                res.emplace_back(std::vector<int>{ intervals[i][0], toBeRemoved[0] });
                res.emplace_back(std::vector<int>{ toBeRemoved[1], intervals[i][1] });
            }
        }
        
        return res;
    }
};