class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        std::vector<int> row = grid.back();
        int n = grid.size();
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int min = INT32_MAX;
                
                for (int k = 0; k < n; ++k) {
                    if (k == j) {
                        continue;
                    }
                    
                    min = std::min(min, grid[i][j] + row[k]);
                }
                
                grid[i][j] = min;
            }
            
            std::swap(row, grid[i]);
        }
        
        int min = row[0];
        for (int i = 1; i < n; ++i) {
            min = std::min(min, row[i]);
        }
        
        return min;
    }
};