class Solution {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    
public:
    int find_set(int v) {
      if (v == parent[v]) {
        return v;
      }
      return parent[v] = find_set(parent[v]);
    }

    int union_sets(int a, int b) {
      a = find_set(a);
      b = find_set(b);

      if (a != b) {
        if (rank[a] < rank[b]) {
          std::swap(a, b);
        }

        parent[b] = a;

        if (rank[a] == rank[b]) {
          ++rank[a];
        }
      }
        
        return a;
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        parent.resize(positions.size(), 0);
        std::iota(parent.begin(), parent.end(), 0);
        
        rank.resize(positions.size(), 0);
        
        std::vector<std::vector<int>> data(m, std::vector<int>(n, 0));
        std::vector<int> res(positions.size(), 0);
        std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int count = 0;
        
        for (int i = 0; i < positions.size(); ++i) {
            int row = positions[i][0];
            int col = positions[i][1];
            
            if (data[row][col] != 0) {
                res[i] = count;
                continue;
            }
            
            int set = -1;
            
            for (int j = 0; j < directions.size(); ++j) {
                int r = directions[j][0] + row;
                int c = directions[j][1] + col;
                
                if (r >= 0 && r < m && c >= 0 && c < n && data[r][c] != 0) {
                    if (set == -1) {
                        set = data[r][c];
                        continue;
                    }
                    
                    if (set != data[r][c]) {
                        int a = find_set(data[r][c] - 1);
                        int b = find_set(set - 1);
                        
                        if (a != b) {
                            set = union_sets(a, b) + 1;
                            --count;
                        }
                    }
                }
            }
            
            if (set == -1) {
                data[row][col] = i + 1;
                ++count;
            } else {
                data[row][col] = set;
            }
            
            res[i] = count;
        }
        
        return res;
    }
}; 