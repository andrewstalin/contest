class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        std::vector<int> cities(n);
        for (const auto& road : roads) {
            ++cities[road[0]];
            ++cities[road[1]];
        }
        
        std::sort(cities.begin(), cities.end(), std::greater<int>());
        
        long long res = 0;
        for (long long val : cities) {
            res += val*n;
            --n;
        }
        
        return res;
    }
};