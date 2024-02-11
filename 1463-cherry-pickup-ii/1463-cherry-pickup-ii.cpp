
class Solution {
public:
    
    int func(int r1, int r2, int row, const std::vector<std::vector<int>>& grid, std::vector<std::vector<std::vector<int>>>& dp) {
        if (row >= grid.size()) {
            return 0;
        }
        
        if (dp[row][r1][r2] != -1) {
            return dp[row][r1][r2];
        }
        
        int next = row + 1;
        dp[row][r1][r2] = func(r1, r2,  next, grid, dp);
        if (r1 + 1 < r2) {
            dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1, r2 - 1, next, grid, dp));
        }
        if (r2 + 1 < grid[0].size()) {
            dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1, r2 + 1, next, grid, dp));
        }
                    
        if (r1 > 0) {
            dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1 - 1, r2 - 1, next, grid, dp));
            dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1 - 1, r2,  next, grid, dp));
            
            if (r2 + 1 < grid[0].size()) {
                dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1 - 1, r2 + 1,  next, grid, dp));
            }
        }
        
        if (r1 + 1 < grid[0].size()) {
            if (r1 + 1 < r2 - 1) {
                dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1 + 1, r2 - 1,  next, grid, dp));
            }
                        
            if (r1 + 1 < r2) {
                dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1 + 1, r2,  next, grid, dp));
            }
                        
            if (r2 + 1 < grid[0].size()) {
                dp[row][r1][r2] = std::max(dp[row][r1][r2], func(r1 + 1, r2 + 1,  next, grid, dp));
            }  
        }
        
        dp[row][r1][r2] += grid[row][r1] + grid[row][r2];
        return dp[row][r1][r2];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        std::vector<std::vector<std::vector<int>>> dp(grid.size(), std::vector<std::vector<int>>(grid[0].size(), std::vector<int>(grid[0].size(), -1)));
        return func(0, grid[0].size() - 1, 0, grid, dp);
    }

};