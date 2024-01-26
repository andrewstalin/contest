class Solution {
private:
    std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
public:
    int func(int m, int r, int c, int row, int col, std::vector<std::vector<int>>& dp) {

        if (m == 0) {
            return 0;
        }
        
        int index = r*col + c;
        --m;
        
        if (dp[m][index] != -1) {
            return dp[m][index];
        }
        
        uint64_t val = 0;
        
        for (int i = 0; i < directions.size(); ++i) {
            int r0 = r + directions[i][0];
            int c0 = c + directions[i][1];
            
            if (r0 < 0 || c0 < 0 || r0 >= row || c0 >= col) {
                ++val;
                continue;
            }
            
            val += func(m, r0, c0, row, col, dp);
        }
        
        val %= 1000000007;
        
        dp[m][index] = val;
        return dp[m][index];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) {
            return 0;
        }
        
        std::vector<std::vector<int>> dp(maxMove, std::vector<int>(m*n, -1));
        return func(maxMove, startRow, startColumn, m, n, dp);
    }
};