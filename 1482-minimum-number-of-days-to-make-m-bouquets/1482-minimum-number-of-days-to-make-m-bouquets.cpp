class Solution {
public:
    inline bool check(int val, const std::vector<int>& bloomDay, int m, int k) {
        int index = 0;
        int end = bloomDay.size() - k;
        
        while (index <= end && m > 0) {
            if (bloomDay[index] > val) {
                ++index;
                continue;
            }
            
            int i = 0;
            while (i < k) {
                if (bloomDay[index] > val) {
                    ++index;
                    break;
                }
                
                ++i;
                ++index;
            }
            
            if (i == k) {
                --m;
            }
        }
        
        return m == 0;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < static_cast<size_t>(m)*k) {
            return -1;
        }
        
        int l = bloomDay[0];
        int r = bloomDay[0];
        
        for (int val : bloomDay) {
            l = std::min(l, val);
            r = std::max(r, val);
        }
        
        --l;
        ++r;
        
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            
            if (check(mid, bloomDay, m, k)) {
                r = mid; 
            } else {
                l = mid;
            }
            
        }
        
        return r;
    }
};