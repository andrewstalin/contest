class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
        });
        
        int res = 0;
        int end = points[0][1];
        
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= end) {
                end = std::min(end, points[i][1]);
            } else {
                end = points[i][1];
                ++res;
            }
        }
        
        return res + 1;
    }
};