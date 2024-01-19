class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int row = (matrix.size() - 2); row >= 0; --row) {
            int prev_row = row + 1;
            
            for (int col = 0; col < matrix[0].size(); ++col) {
                int min = INT32_MAX;
                
                if (col > 0) {
                    min = matrix[prev_row][col - 1];    
                }
                
                min = std::min(min, matrix[prev_row][col]);
                
                if (col + 1 < matrix[0].size()) {
                    min = std::min(min, matrix[prev_row][col + 1]);    
                }
                
                matrix[row][col] += min;
            }
        }
        
        int res = matrix[0][0];
        for (int i = 1; i < matrix[0].size(); ++i) {
            res = std::min(res, matrix[0][i]);
        }
        return res;
    }
};