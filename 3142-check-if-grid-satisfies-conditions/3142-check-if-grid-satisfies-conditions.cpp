class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
 
        for (size_t col = 0; col < (grid[0].size() - 1); ++col) {
            if (grid[0][col] == grid[0][col + 1]) {
                return false;
            }
        }
        
        for (size_t col = 0; col < (grid[0].size()); ++col) {
            int val = grid[0][col];
            
            for (size_t row = 1; row < grid.size(); ++row) {
                if (grid[row][col] != val) {
                    return false;
                }
            } 
        }
        
        return true;
    }
};