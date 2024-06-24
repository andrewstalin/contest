class Solution {
public:
    inline int next(int pos, int val, const std::vector<int>& position) {
        int l = pos;
        int r = position.size();
        
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            
            if (position[mid] - position[pos] >= val) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
    }
    
    inline int next2(int pos, int val, const std::vector<int>& position) {
        int begin = position[pos];
        ++pos;
        
        while (pos < position.size()) {
            if (position[pos] - begin >= val) {
                return pos;
            }
            ++pos;
        }
        
        return pos;
    }
    
    inline bool check(int val, int m, const std::vector<int>& position) {
        int index = 0;
        --m;
        
        while (index < position.size() && m > 0) {
            index = next2(index, val, position);
            
            if (index < position.size()) {
                --m;
            }
        }
        
        return m == 0;
    }
    
    int maxDistance(vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        int l = 0;
        int r = position.back() + 1;
        
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            
            if (check(mid, m, position)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};