class Solution {
public:
    void flip_col(int col, std::vector<std::vector<int>>& grid) {
        size_t zero = 0;
        for (size_t row = 0; row < grid.size(); ++row) {
            if (grid[row][col] == 0) {
                ++zero;
            }
        }
        
        if (grid.size() - zero < zero) {
            for (size_t row = 0; row < grid.size(); ++row) {
                grid[row][col] = grid[row][col] == 1 ? 0 : 1;
            }
        }
    }
    
    void flip_rows(std::vector<std::vector<int>>& grid) {
        for (size_t row = 0; row < grid.size(); ++row) {
            if (grid[row][0] == 1) {
                continue;
            }
            
            for (size_t col = 0; col < grid[0].size(); ++col) {
                grid[row][col] = grid[row][col] == 1 ? 0 : 1;
            }
        }
    }
    
    int sum(const std::vector<std::vector<int>>& grid) {
        int res = 0;
        
        for (size_t row = 0; row < grid.size(); ++row) {
            int val = 0;
            
            for (size_t col = 0; col < grid[0].size(); ++col) {
                val <<= 1;
                val |= grid[row][col];
            }
            
            res += val;
        }
        
        return res;
    }
    
    
    int matrixScore(vector<vector<int>>& grid) {
        size_t col = 0;
        
        for (size_t row = 0; row < grid.size(); ++row) {
            if (grid[row][0] == 1) {
                flip_rows(grid);
                col = 1;
                break;
            }
        }
        
        while (col < grid[0].size()) {
            flip_col(col, grid);
            ++col;
        }
            
        return sum(grid);
    }
};