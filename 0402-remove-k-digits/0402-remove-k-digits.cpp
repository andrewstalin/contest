class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        
        std::string res;
        res.reserve(num.size());
        
        int index = 0;
        
        while (k > 0 && index < num.size()) {
            if (!res.empty() && res.back() > num[index]) {
                res.resize(res.size() - 1);
                --k;
                continue;
            }
            
            int next = index + 1;
            
            if (next < num.size() && num[index] > num[next]) {
                --k;
            } else if (!res.empty() || num[index] != '0') {
                res.push_back(num[index]);
            }
            
            ++index;
        }
        
        if (k > 0) {
            if (k >= res.size()) {
                res = "";
            } else {
                res.resize(res.size() - k);
            }
        } else if (index < num.size()) {
            while(index < num.size()) {
                if (!res.empty() || num[index] > '0') {
                    res.push_back(num[index]);
                }
                ++index;
            }
        }
        
        return res.empty() ? "0" : res;
    }
};

/*


"1432219"
3
"10200"
1
"10"
2
"112"
1
"12345"
2
"10"
1
"10001"
4


*/
