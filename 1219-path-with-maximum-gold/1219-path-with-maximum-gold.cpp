class Solution {
private:
    std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int func(int row, int col, std::vector<std::vector<int>>& grid) {
        int val = grid[row][col];
        grid[row][col] = 0;
        int max = 0;
        
        for (const auto& direction : directions) {
            int r = row + direction[0];
            int c = col + direction[1];
            
            if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
                continue;
            }
            
            max = std::max(max, func(r, c, grid));
        }
        
        grid[row][col] = val;
        return val + max;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] != 0) {
                    res = std::max(res, func(row, col, grid));
                }
            }
        }
        
        return res;
    }
};