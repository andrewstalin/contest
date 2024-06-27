class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::vector<bool> data(edges.size() + 2);
        for (const auto& edge : edges) {
            if (data[edge[0]]) {
                return edge[0];
            }
            
            data[edge[0]] = true;
            
            if (data[edge[1]]) {
                return edge[1];
            }
            
            data[edge[1]] = true;
        }
        
        return -1;
    }
};