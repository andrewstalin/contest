class Solution {
public:
    int find_left(int val, const std::vector<std::vector<int>>& intervals) {
        int l = -1;
        int r = intervals.size();
        
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            
            if (intervals[mid][1] < val) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
    
    int find_right(int val, const std::vector<std::vector<int>>& intervals) {
        int l = -1;
        int r = intervals.size();
        
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            
            if (intervals[mid][0] > val) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> res;
        res.reserve(intervals.size() + 1);
        
        if (intervals.empty()) {
            res.emplace_back(std::move(newInterval));
            return res;
        }
        
        int l = find_left(newInterval[0], intervals);
        int r = find_right(newInterval[1], intervals);
         
        for (int i = 0; i <= l; ++i) {
            res.emplace_back(std::move(intervals[i]));
        }
        
        if (r - l == 1) {
            res.emplace_back(std::move(newInterval));
        } else {
            newInterval[0] = std::min(newInterval[0], intervals[l + 1][0]);
            newInterval[1] = std::max(newInterval[1], intervals[r - 1][1]);
            res.emplace_back(std::move(newInterval));
        }
        
        for (int i = r; i < intervals.size(); ++i) {
            res.emplace_back(std::move(intervals[i]));
        }
              
        return res;
    }
};



/*

[[2,4],[5,7],[8,10],[11,13]]
[3,8]
[[0,5],[9,12]]
[7,16]
[[1,5]]
[0,0]
[[1,2],[3,5],[6,7],[8,10],[12,16]]
[4,8]
[[1,3],[6,9]]
[2,5]
[[1,2],[3,5],[6,7],[8,10],[12,16]]
[4,8]




*/




