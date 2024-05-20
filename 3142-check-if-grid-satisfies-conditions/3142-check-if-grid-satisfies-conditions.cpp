class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        size_t last_row = grid.size() - 1;
        size_t last_col = grid[0].size() - 1;
        
        for (size_t row = 0; row < grid.size(); ++row) {
            for (size_t col = 0; col < grid[0].size(); ++col) {
                if ((row != last_row && grid[row][col] != grid[row + 1][col])
                        || (col != last_col && grid[row][col] == grid[row][col + 1])) {
                    return false;
                }
            }
        }
        
        return true;
    }
};