class Solution {
public:
    int get_max(int row, int col, const std::vector<std::vector<int>>& grid) {
        int col2 = col + 1;
        int col3 = col + 2;
        int r1 = std::max(grid[row][col], std::max(grid[row][col2], grid[row][col3]));
        ++row;
        int r2 = std::max(grid[row][col], std::max(grid[row][col2], grid[row][col3]));
        ++row;
        int r3 = std::max(grid[row][col], std::max(grid[row][col2], grid[row][col3]));
        return std::max(r1, std::max(r2, r3));
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {        
        std::vector<std::vector<int>> res(grid.size() - 2, std::vector<int>(grid.size() - 2, 0));
        
        for (size_t row = 0, end = grid.size() - 2; row < end; ++row) {
            for (size_t col = 0; col < end; ++col) {
                res[row][col] = get_max(row, col, grid);
            }
        }

        return res;
    }
};