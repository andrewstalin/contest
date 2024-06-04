class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[0] < v2[0];
        });
        
        int last = 0;
        int res = 0;
        
        for (size_t i = 0; i < meetings.size(); ++i) {
            if (last >= meetings[i][0]) {
                last = std::max(last, meetings[i][1]);
                continue;
            }
            
            res += meetings[i][0] - last - 1;
            last = meetings[i][1];
        }
        
        return res + (days - last);
    }
};