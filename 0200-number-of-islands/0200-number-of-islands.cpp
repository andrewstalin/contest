class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        std::queue<std::pair<int, int>> queue;
        std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    ++res;
                    queue.emplace(row, col);
                    grid[row][col] = '0';
                    
                    while (!queue.empty()) {
                        auto item = queue.front();
                        queue.pop();
                        
                        for (int i = 0; i < 4; ++i) {
                            int r = item.first + directions[i][0];
                            int c = item.second + directions[i][1];
                            
                            if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') {
                                continue;
                            }
                            
                            queue.emplace(r, c);
                            grid[r][c] = '0';
                        }
                    }
                }
            }
        }
        
        return res;
    }
};