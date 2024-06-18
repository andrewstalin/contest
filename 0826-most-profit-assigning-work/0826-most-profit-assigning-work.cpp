class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::vector<int> index(difficulty.size());
        std::iota(index.begin(), index.end(), 0);
        
        std::sort(index.begin(), index.end(), [&profit](int i1, int i2){
            return profit[i1] > profit[i2];
        });
        
        std::sort(worker.begin(), worker.end(), std::greater<int>());
        
        int res = 0;
        size_t w = 0;
        size_t i = 0;
        
        while (i < index.size() && w < worker.size()) {
            if (difficulty[index[i]] > worker[w]) {
                ++i;
                continue;
            }
            
            res += profit[index[i]];
            ++w;
        }
        
        return res;
    }
};