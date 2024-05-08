struct City {
    int to;
    int cost;
    
    City(int to, int cost): to(to), cost(cost) {}
};

long long func(int n, long long path, std::vector<bool>& visited, const std::vector<std::vector<City>>& data, const std::vector<int>& appleCost, int k, long long min) {
    min = std::min(min, path + appleCost[n]);
    
    long long cost;    
    for (size_t j = 0; j < data[n].size(); ++j) {
        const auto& city = data[n][j];
                    
        if (visited[city.to]) {
            continue;
        }
                    
        cost = path + (k + 1)*city.cost;
                    
        if (cost < min) {
            visited[city.to] = true;
            min = std::min(min, func(city.to, cost, visited, data, appleCost, k, min));
            visited[city.to] = false;
        }
    }
    
    return min;
}


class Solution {
public:
    
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        std::vector<std::vector<City>> data(n, std::vector<City>());
        for (size_t i = 0; i < roads.size(); ++i) {
            data[roads[i][0] - 1].emplace_back(roads[i][1] - 1, roads[i][2]);
            data[roads[i][1] - 1].emplace_back(roads[i][0] - 1, roads[i][2]);
        }
        
        std::vector<long long> res(n, 0);
        std::vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            visited[i] = true;
            res[i] = func(i, 0, visited, data, appleCost, k, appleCost[i]);
            visited[i] = false;
        }
        
        return res;
    }
};