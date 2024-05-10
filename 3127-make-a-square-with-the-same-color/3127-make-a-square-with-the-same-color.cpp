class Solution {
public:
    bool check(int row, int col, const std::vector<std::vector<char>>& grid) {
        int w = 0;
        int b = 0;
        
        if (grid[row][col] == 'B') {
            ++b;
        } else {
            ++w;
        }
        
        if (grid[row][col + 1] == 'B') {
            ++b;
        } else {
            ++w;
        }
        
        if (grid[row + 1][col] == 'B') {
            ++b;
        } else {
            ++w;
        }
        
        if (grid[row + 1][col + 1] == 'B') {
            ++b;
        } else {
            ++w;
        }
        
        return b >= 3 || w >= 3; 
    }
    
    bool canMakeSquare(vector<vector<char>>& grid) {
        return check(0, 0, grid) || check(0, 1, grid) || check(1, 0, grid) || check(1, 1, grid) ;
    }
};