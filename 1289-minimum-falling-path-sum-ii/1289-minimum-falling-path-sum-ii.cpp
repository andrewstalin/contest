struct Item {
    int min1;
    int col1;
    int min2;
    int col2;

    Item(int min1, int col1, int min2, int col2): min1(min1), col1(col1), min2(min2), col2(col2) {}
};

class Solution {
public:
    inline Item find_min(const std::vector<int>& row, const Item& prev) {
        int min1 = INT32_MAX;
        int col1 = -1;

        int min2 = INT32_MAX;
        int col2 = -1;
        
        int val;
        
        for (int i = 0; i < row.size(); ++i) {
            if (i != prev.col1) {
                val = prev.min1 + row[i];
            } else {
                val = prev.min2 + row[i];
            }
            
            if (min1 >= val) {
                min2 = min1;
                col2 = col1;
                min1 = val;
                col1 = i;
            } else if (min2 > val) {
                col2 = i;
                min2 = val;
            } 
        }
        
        return Item(min1, col1, min2, col2);
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 1) {
            return grid[0][0];
        }
        
        Item item(0, -1, 0, -1);
        
        for (int i = (grid.size() - 1); i >= 0; --i) {
            item = find_min(grid[i], item);
        }
        
        return item.min1;
    }
};