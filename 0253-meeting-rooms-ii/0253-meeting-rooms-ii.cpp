class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[0] < v2[0];
        });
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        size_t res{ 0 };
        
        for (const auto& interval : intervals) {
            while (!queue.empty() && queue.top() <= interval[0]) {
                queue.pop();
            }
            
            queue.emplace(interval[1]);
            res = std::max(res, queue.size());
        }
        
        return res;
    }
};