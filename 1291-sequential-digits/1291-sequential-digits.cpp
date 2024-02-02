class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int head = 1;
        int val = 12;
        int k = 3;
        
        std::vector<int> res;
        
        while (head < 9) {
            if (val >= low && val <= high) {
                res.emplace_back(val);
            }
            
            if (k == 10) {
                ++head;
                k = head + 2;
                val = head*10 + (head + 1);
                continue;
            }
            
            val *= 10;
            val += k;
            ++k;
        }
        
        std::sort(res.begin(), res.end());
        return res;
    }
};