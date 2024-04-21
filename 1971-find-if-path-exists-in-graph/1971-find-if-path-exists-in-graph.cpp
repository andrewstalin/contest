class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }
        
        std::vector<std::vector<int>> data(n, std::vector<int>());
        for (int i = 0; i < edges.size(); ++i) {
            data[edges[i][0]].push_back(edges[i][1]);
            data[edges[i][1]].push_back(edges[i][0]);
        }
        
        std::queue<int> queue;
        queue.emplace(source);
        
        std::vector<bool> visited(n, false);
        visited[source] = true;
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            
            for (int i = 0; i < data[node].size(); ++i) {
                if (visited[data[node][i]]) {
                    continue;
                }
                
                if (data[node][i] == destination) {
                    return true;
                }
                
                queue.emplace(data[node][i]);
                visited[data[node][i]] = true;
            }
        }
        
        return false;
    }
};