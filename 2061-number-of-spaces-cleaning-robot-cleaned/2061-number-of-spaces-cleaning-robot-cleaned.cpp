class Solution {
public:
    
    int numberOfCleanRooms(vector<vector<int>>& room) {
        std::vector<std::vector<uint8_t>> space(room.size(), std::vector<uint8_t>(room[0].size()));
        int res = 0;
        int row = 0;
        int col = 0;
        
        // left=1, up=2, right=3, down=4 
        uint8_t direction = 3;
        
        while (true) {
            auto& spot = space[row][col];
            
            if (((1 << direction) & spot) != 0) {
                break;
            }
            
            if (spot == 0) {
                ++res;
            }
            
            spot |= (1 << direction);
            int count = 0;
        
            while (count < 5) {
                ++count;
                
                if (direction == 1) {
                    if (col > 0 && room[row][col - 1] == 0) {
                        --col;
                        break;
                    } 

                    ++direction;
                } else if (direction == 2) {
                    if (row > 0 && room[row - 1][col] == 0) {
                        --row;
                        break;
                    }
                    
                    ++direction;
                } else if (direction == 3) {
                    if (col + 1 < room[0].size() && room[row][col + 1] == 0) {
                        ++col;
                        break;
                    }
                    
                    ++direction;
                } else {
                    if (row + 1 < room.size() && room[row + 1][col] == 0) {
                        ++row;
                        break;
                    }
                    
                    direction = 1;
                }
            }
            
            if (count == 5) {
                break;
            }
        }
        
        return res;
    }
};