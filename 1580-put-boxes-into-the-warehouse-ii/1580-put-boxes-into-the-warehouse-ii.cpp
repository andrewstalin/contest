class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        std::vector<int> index(warehouse.size(), 0);
        std::iota(index.begin(), index.end(), 0);
        
        std::sort(index.begin(), index.end(), [&warehouse](int i1, int i2){
            return warehouse[i1] < warehouse[i2];
        });
        
        int l = INT32_MAX;
        int r = INT32_MIN;
        size_t warehouse_index = 0;
        
        std::sort(boxes.begin(), boxes.end());
        size_t box_index = 0;
        int res = 0;
        
        while (warehouse_index < warehouse.size() && box_index < boxes.size()) {
            int val = warehouse[index[warehouse_index]];
            int nextl = l;
            int nextr = r;
            
            while (warehouse_index < warehouse.size() && val == warehouse[index[warehouse_index]]) {
                nextl = std::min(nextl, index[warehouse_index]);
                nextr = std::max(nextr, index[warehouse_index]);
                ++warehouse_index;
            }
            
            int count = 0;
            if (l == INT32_MAX) {
                count = nextr - nextl + 1;
            } else {
                if (l != nextl) {
                    count += (l - nextl);
                }
                
                if (r != nextr) {
                    count += (nextr - r);
                }
            }
            
            while (count > 0 && box_index < boxes.size() && boxes[box_index] <= val) {
                ++res;
                --count;
                ++box_index;
            }
            
            l = std::min(l, nextl);
            r = std::max(r, nextr);
        }
        
        return res;
    }
};