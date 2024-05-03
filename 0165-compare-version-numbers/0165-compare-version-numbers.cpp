class Solution {
public:
    int to_dot(const std::string& s, int pos) {
        while (pos < s.size() && s[pos] != '.') {
            ++pos;
        }
        
        return pos < s.size() ? pos : -1;
    }
    
    int to_int(const std::string& s, int l, int r) {
        if (r < 0) {
            r = s.size();
        }
        
        int result = 0;
        
        while (l < r) {
            result *= 10;
            result += (s[l] - '0');
            ++l;
        }
        
        return result;
    }
    
    bool all_zero(const std::string& version, int l, int r) {
        while (l > 0) {
            int v = to_int(version, l, r);
            
            if (v != 0) {
                return false;
            }
            
            l = r > 0 ? r + 1 : -1;    
            r = to_dot(version, l);
        }
        
        return true;
    }
    
    int compareVersion(string version1, string version2) {
        int l1 = 0;
        int l2 = 0;
        int r1 = to_dot(version1, 0);
        int r2 = to_dot(version2, 0);
        
        while (l1 >= 0 && l2 >= 0) {
            int v1 = to_int(version1, l1, r1);
            int v2 = to_int(version2, l2, r2);
            
            if (v1 == v2) {
                l1 = r1 > 0 ? r1 + 1 : -1;
                l2 = r2 > 0 ? r2 + 1 : -1;
                
                r1 = to_dot(version1, l1);
                r2 = to_dot(version2, l2);
            } else {
                return v1 > v2 ? 1 : -1;
            }
        }
        
        if (l1 > 0 && !all_zero(version1, l1, r1)) {
            return 1;
        }
        
        if (l2 > 0 && !all_zero(version2, l2, r2)) {
            return -1;
        }
        
        return 0;
    }
};