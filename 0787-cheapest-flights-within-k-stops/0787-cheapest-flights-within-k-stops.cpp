struct Flight {
    int dst;
    int price;
    
    Flight(int dst, int price): dst(dst), price(price) {}
};

struct Trip {
    int city;
    int sum;
    int hop;
    
    Trip(int city, int sum, int hop): city(city), sum(sum), hop(hop) {}
};

class Solution {
public:    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        std::vector<std::vector<Flight>> data(n, std::vector<Flight>());
        for (int i = 0; i < flights.size(); ++i) {
            data[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
        }
        
        auto cmp = [](const Trip& t1, const Trip& t2){
            return t1.sum > t2.sum;
        };
        std::priority_queue<Trip, std::vector<Trip>, decltype(cmp)> queue(cmp);
        
        std::vector<std::vector<int>> visited(n, std::vector<int>(k + 1, -1));
        for (int i = 0; i <= k; ++i) {
            visited[src][i] = 0;
        }
        
        queue.emplace(src, 0, -1);
        
        while (!queue.empty()) {
            auto item = queue.top();
            queue.pop();
            
            if (item.city == dst && item.hop <= k) {
                return item.sum;
            }
            
            ++item.hop;
            
            if (item.hop > k) {
                continue;
            }
            
            const auto& dst_flights = data[item.city];
            
            for (int i = 0; i < dst_flights.size(); ++i) {
                int sum = data[item.city][i].price + item.sum;
                
                if (visited[dst_flights[i].dst][item.hop] != -1 && visited[dst_flights[i].dst][item.hop] <= sum) {
                    continue;
                }

                visited[dst_flights[i].dst][item.hop] = sum;
                queue.emplace(data[item.city][i].dst, data[item.city][i].price + item.sum, item.hop);
            } 
        }
        
        return -1;
    }
};