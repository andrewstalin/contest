class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int c = 0; c < matrix[0].size(); ++c) {
            int max = -2;
            bool negative = false;
            
            for (int r = 0; r < matrix.size(); ++r) {
                max = std::max(max, matrix[r][c]);
                
                if (matrix[r][c] < 0) {
                    negative = true;
                }
            }
            
            if (negative) {
                for (int r = 0; r < matrix.size(); ++r) {
                    if (matrix[r][c] < 0) {
                        matrix[r][c] = max;
                    }
                }
            }
        }
        
        return matrix;
    }
};