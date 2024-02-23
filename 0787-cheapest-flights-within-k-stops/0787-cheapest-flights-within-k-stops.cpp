struct Flight {
    int dst;
    int price;
    
    Flight(int dst, int price): dst(dst), price(price) {}
};

struct City {
    std::vector<Flight> flights;
    int price{ INT32_MAX };
};

struct Trip {
    int city;
    int price;
    int count;
    
    Trip(int city, int price, int count): city(city), price(price), count(count) {}
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<City> data(n, City());
        
        for (int i = 0; i < flights.size(); ++i) {
            data[flights[i][0]].flights.emplace_back(flights[i][1], flights[i][2]);
        }
        
        data[src].price = 0;
        std::queue<Trip> queue;
        queue.emplace(src, 0, 0);
        
        while (!queue.empty()) {
            auto trip = queue.front();
            queue.pop();
            
            if (trip.count > k) {
                continue;
            }
            
            for (int i = 0; i < data[trip.city].flights.size(); ++i) {
                const auto& flight = data[trip.city].flights[i];
                int price = trip.price + flight.price;
                
                if (trip.count<= k && data[flight.dst].price > price) {
                    data[flight.dst].price = price;
                    
                    if (trip.city != dst) {
                        queue.emplace(flight.dst, price, trip.count + 1);
                    }
                }
            }
        }
        
        return data[dst].price == INT32_MAX ? -1 : data[dst].price;
    }
};