class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        std::vector<int> data(24, 0);
        long long res = 0;
        
        int hour;
        for (int val : hours) {
            hour = val % 24;
            
            if (hour == 0) {
                res += data[0];
                ++data[0];
                continue;
            }
            
            res += data[24 - hour];
            ++data[hour];
        }
        
        return res;
    }
};