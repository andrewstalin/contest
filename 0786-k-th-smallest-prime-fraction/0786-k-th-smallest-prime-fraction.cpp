struct Item {
    int l;
    int r;
    double fraction;
    
    Item(int l, int r, double fraction): l(l), r(r), fraction(fraction) {}
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [](const Item& i1, const Item& i2){
            return i1.fraction > i2.fraction;
        };
        std::priority_queue<Item, std::vector<Item>, decltype(cmp)> queue(cmp);
        
        for (size_t i = 0, r = arr.size() - 1; i < arr.size(); ++i) {
            queue.emplace(i, r, static_cast<double>(arr[i])/arr[r]);
        }
        
        while (true) {
            --k;
            auto item = queue.top();
            queue.pop();
            
            if (k == 0) {
                return std::vector<int>{ arr[item.l], arr[item.r] };
            }
            
            --item.r;
            
            if (item.l < item.r) {
                queue.emplace(item.l, item.r, static_cast<double>(arr[item.l])/arr[item.r]);
            }
        }
        
        return std::vector<int>();
    }
};