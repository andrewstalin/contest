struct Trie {
    std::vector<Trie*> nodes;
    
    Trie(): nodes(10, nullptr) {}
};


struct Item {
    Trie* t1;
    Trie* t2;
    int count;
    
    Item(Trie* t1, Trie* t2, int count): t1(t1), t2(t2), count(count) {}
};

class Solution {
public:
    Trie build(const std::vector<int>& arr) {
        Trie root;
        
        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            int divider = 1;
            int count = 1;
            
            while (val >= 10) {
                divider *= 10;
                val /= 10;
                ++count;
            }
            
            val = arr[i];
            Trie* node = &root;
            int d;
            
            while (count > 0) {
                --count;
                d = val / divider;
                
                if (node->nodes[d] == nullptr) {
                    node->nodes[d] = new Trie();
                }
                
                node = node->nodes[d];
                val %= divider;
                divider /= 10;
            }
        }
        
        return root;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        auto tree1 = build(arr1);
        auto tree2 = build(arr2);
        
        std::stack<Item> stack;
        int res = 0;
        
        stack.emplace(&tree1, &tree2, 0);
        
        while (!stack.empty()) {
            auto item = stack.top();
            stack.pop();
            
            res = std::max(res, item.count);
            ++item.count;
            
            for (int i = 0; i < 10; ++i) {
                if (item.t1->nodes[i] != nullptr && item.t2->nodes[i] != nullptr) {
                    stack.emplace(item.t1->nodes[i], item.t2->nodes[i], item.count);
                }
            }
        }
        
        return res;
    }
};