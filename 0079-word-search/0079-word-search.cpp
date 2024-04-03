
struct Item {
    uint64_t mask;
    size_t pos;
    int16_t row;
    int16_t col;
    
    Item(uint64_t mask, size_t pos, int16_t row, int16_t col): mask(mask), pos(pos), row(row), col(col) {}
};

class Solution {
public:    
    bool exist(vector<vector<char>>& board, string word) {
        std::queue<Item> queue;
        int16_t row_count = board.size();
        int16_t col_count = board[0].size();
        
        for (int16_t row = 0; row < row_count; ++row) {
            for (int16_t col = 0; col < col_count; ++col) {
                if (word[0] == board[row][col]) {
                    if (word.size() == 1) {
                        return true;
                    }
                    
                    uint64_t mask = (1ul << (row*col_count + col));
                    queue.emplace(mask, 1, row, col);
                }
            }
        }
        
        std::vector<std::vector<int16_t>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.empty()) {
            auto item = queue.front();
            queue.pop();
            
            if (item.pos == 9) {
                int stop = 1;
            }
            
            size_t pos = item.pos;
            ++item.pos;
            
            for (int i = 0; i < directions.size(); ++i) {
                int16_t r = item.row + directions[i][0];
                int16_t c = item.col + directions[i][1];
                
                if (r < 0 || r >= row_count || c < 0 || c >= col_count 
                    || (item.mask & (1ul << (r*col_count + c))) != 0
                    || board[r][c] != word[pos]) {
                    continue;
                }
                
                if (item.pos == word.size()) {
                    return true;
                }
                
                uint64_t mask = item.mask | (1ul << (r*col_count + c));
                queue.emplace(mask, item.pos, r, c);
            }
        }
        
        return false;
    }
};


/*

[["a"]]
"a"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"SEE"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB"
[["b","b","a","a","b","a"],["b","b","a","b","a","a"],["b","b","b","b","b","b"],["a","a","a","b","a","a"],["a","b","a","a","b","b"]]
"abbbababaa"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["C","A","A"],["A","A","A"],["B","C","D"]]
"AAB"
[["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
"AAAAAAAAAAAAAAB"
[["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
"ABCESEEEFS"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB"

*/


