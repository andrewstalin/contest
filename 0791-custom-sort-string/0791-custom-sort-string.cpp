class Solution {
public:
    string customSortString(string order, string s) {
        std::vector<int> data(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++data[s[i] - 'a'];
        }
        
        int index{ 0 };
        
        for (int i = 0; i < order.size(); ++i) {
            int k = order[i] - 'a';
            
            while (data[k] > 0) {
                s[index] = order[i];
                ++index;
                --data[k];
            }
        }
        
        for (int i = 0; i < data.size(); ++i) {
            while (data[i] > 0) {
                s[index] = i + 'a';
                ++index;
                --data[i];
            }
        }
        
        return s;
    }
};