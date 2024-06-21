class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        std::vector<int> data(customers.size());
        std::vector<int> sum(customers.size());
        
        data[0] = grumpy[0] == 0 ? customers[0] : 0;
        sum[0] = customers[0];
        
        for(size_t i = 1; i < customers.size(); ++i) {
            sum[i] = sum[i - 1] + customers[i];
            data[i] = data[i - 1] + (grumpy[i] == 0 ? customers[i] : 0);
        }
        
        if (minutes >= customers.size()) {
            return sum.back();
        }
        
        int res = sum[minutes - 1] + data.back() - data[minutes - 1];
        
        for (size_t i = minutes; i < customers.size(); ++i) {
            int val = sum[i] - sum[i - minutes] + data[i - minutes] + data.back() - data[i];
            res = std::max(res, val);
        }
        
        return res;
    }
};