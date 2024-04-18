class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    if (row == 0 || grid[row - 1][col] == 0) {
                        ++res;
                    }
                    
                    if (col == 0 || grid[row][col - 1] == 0) {
                        ++res;
                    }
                    
                    if (row + 1 >= grid.size() || grid[row + 1][col] == 0) {
                        ++res;
                    }
                    
                    if (col + 1 >= grid[0].size() || grid[row][col + 1] == 0) {
                        ++res;
                    }
                }
            }
        }
        
        return res;
    }
};