class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        std::sort(power.begin(), power.end());
        
        std::vector<std::pair<int, long long>> data(3, std::make_pair(INT32_MAX, 0));
        int index = power.size() - 1; 
        
        while (index >= 0) {
            int val = power[index];
            long long sum = 0;
            
            while (index >= 0 && val == power[index]) {
                sum += power[index];
                --index;
            }
            
            long long max = 0;
            
            if (data[0].first > val + 2) {
                max = std::max(data[0].second, std::max(data[1].second, data[2].second));
            } else if (data[1].first > val + 2) {                
                max = std::max(data[1].second, data[2].second);
            } else {
                max = data[2].second;
            }
            
            std::swap(data[1], data[2]);
            data[2].second = std::max(data[1].second, data[2].second);
            
            std::swap(data[0], data[1]);
            data[1].second = std::max(data[0].second, data[1].second);
            
            data[0].first = val;
            data[0].second = sum + max;
        }
        
        return std::max(data[0].second, std::max(data[1].second, data[2].second));
    }
};