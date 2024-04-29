struct Item {
    int number;
    int path{ 0 };
    int nodes{ 0 };
    int state{ INT32_MIN };
    std::unordered_map<int, std::pair<int, int>> map;
    
    Item(int number): number(number) {}
};

class Solution {
public:
    
    void func(int prev, Item& node, std::vector<Item>& data) {
        
        if (node.state == INT32_MAX) {
            return;
        }
        
        if (node.state == INT32_MIN) {
            node.state = prev;
            
            for (auto it = node.map.begin(); it != node.map.end(); ++it) {
                if (it->first == prev) {
                    continue;
                }
                
                auto& to = data[it->first];
                func(node.number, to, data);
                
                const auto& it_prev = to.map[node.number];

                it->second.first = to.path - it_prev.first + to.nodes - it_prev.second + 1;
                it->second.second = to.nodes - it_prev.second + 1;
                
                node.path += it->second.first;
                node.nodes += it->second.second;
            }
        } else {
            func(node.number, data[node.state], data);
            
            auto& it_cur = node.map[node.state];
            const auto& it_prev = data[node.state].map[node.number];
            
            it_cur.first = data[node.state].path - it_prev.first + data[node.state].nodes - it_prev.second + 1;
            it_cur.second = data[node.state].nodes - it_prev.second + 1;
            
            node.path += it_cur.first;
            node.nodes += it_cur.second;
            node.state = INT32_MAX;
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        std::vector<Item> data;
        data.reserve(n);
        
        for(int i = 0; i < n; ++i) {
            data.emplace_back(i);
        }
        
        for (int i = 0; i < edges.size(); ++i) {
            data[edges[i][0]].map.emplace(edges[i][1], std::make_pair(0, 0));
            data[edges[i][1]].map.emplace(edges[i][0], std::make_pair(0, 0));
        }
        
        std::vector<int> result(n, 0);
        
        for (int i = 0; i < n; ++i) {
            func(INT32_MAX, data[i], data);
            result[i] = data[i].path;
        }
        
        return result;
    }
};