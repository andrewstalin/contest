class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0;
        std::vector<int> tmp(grid[0].size(), 0);
        
        for (int row = 0; row < grid.size(); ++row) {
            int sum = 0;
            
            for (int col = 0; col < grid[0].size(); ++col) {
                tmp[col] += grid[row][col];
                sum += tmp[col];
                
                if (sum > k) {
                    break;
                }
                
                ++res;
            }
        }
        
        return res;
    }
};