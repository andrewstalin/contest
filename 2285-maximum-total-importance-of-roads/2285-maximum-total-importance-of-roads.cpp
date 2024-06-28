class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        std::vector<int> cities(n);
        for (const auto& road : roads) {
            ++cities[road[0]];
            ++cities[road[1]];
        }
        
        std::vector<int> index(n, 0);
        std::iota(index.begin(), index.end(), 0);
        
        std::sort(index.begin(), index.end(), [&cities](int i1, int i2){
            return cities[i1] > cities[i2];
        });
        
        for (int i = 0, k = n; i < cities.size(); ++i, --k) {
            cities[index[i]] = k;
        }
        
        long long res = 0;
        for (const auto& road : roads) {
            res += cities[road[0]] + cities[road[1]];
        }
        
        return res;
    }
};