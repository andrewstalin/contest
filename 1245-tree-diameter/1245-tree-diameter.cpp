struct Item {
    int node;
    int depth{ -1 };
    
    Item(int node): node(node) {}
};

class Solution {
public:
    int calc(int prev, int node, std::vector<std::vector<Item>>& tree) {
        int max = 0;
        
        for (int i = 0; i < tree[node].size(); ++i) {
            if (tree[node][i].node == prev) {
                continue;
            }
            
            if (tree[node][i].depth == -1) {
                tree[node][i].depth = calc(node, tree[node][i].node, tree) + 1;
            }
                
            max = std::max(max, tree[node][i].depth);
        }
        
        return max;
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        std::vector<std::vector<Item>> tree;
        int n = edges.size() + 1;
        tree.resize(n);
        
        for (int i = 0; i < edges.size(); ++i) {
            tree[edges[i][0]].emplace_back(edges[i][1]);
            tree[edges[i][1]].emplace_back(edges[i][0]);
        }
        
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            auto& node = tree[i];
            int d1 = 0;
            int d2 = 0;
            
            for (int k = 0; k < node.size(); ++k) {
                if (node[k].depth == -1) {
                    node[k].depth = calc(i, node[k].node, tree) + 1;
                }
                
                if (d1 <= node[k].depth) {
                    std::swap(d1, d2);
                    d1 = node[k].depth;
                } else if (d2 < node[k].depth) {
                    d2 = node[k].depth;
                }
            }
            
            res = std::max(res, d1 + d2);
        }
        
        return res;
    }
};