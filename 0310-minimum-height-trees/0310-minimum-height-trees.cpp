class Solution {
public:
    int func(int cur, int prev, std::vector<std::vector<std::pair<int, int>>>& data) {
        int max = 0;
        
        for (int i = 0; i < data[cur].size(); ++i) {
            if (prev == data[cur][i].first) {
                continue;
            }
            
            if (data[cur][i].second == -1) {
                data[cur][i].second = func(data[cur][i].first, cur, data);
            }
            
            max = std::max(max, 1 + data[cur][i].second);
        }
        
        return max;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> data(n, std::vector<std::pair<int, int>>());
        for (int i = 0; i < edges.size(); ++i) {
            data[edges[i][0]].emplace_back(edges[i][1], -1);
            data[edges[i][1]].emplace_back(edges[i][0], -1);
        }
        
        std::vector<int> heights(n, 0);
        int min = INT32_MAX;
        
        for (int i = 0; i < n; ++i) {
            heights[i] = func(i, -1, data);
            min = std::min(min, heights[i]);
        }
        
        std::vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            if (heights[i] == min) {
                res.emplace_back(i);
            }
        }
        
        return res;
    }
};