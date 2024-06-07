struct Trie {
    std::vector<int> nodes;
    int word{ -1 };
    
    Trie(): nodes(26, -1) {}
};

class Solution {
public:
    inline size_t move_forward(size_t pos, const std::string& sentence) {
        while (pos < sentence.size() && sentence[pos] != ' ') {
            ++pos;
        } 
        return pos;
    }
    
    inline void add(const std::string& str, std::string& res) {
        if (!res.empty()) {
            res.push_back(' ');
        }
        res.append(str);
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::vector<Trie> trie;
        trie.emplace_back();
        
        for (size_t i = 0; i < dictionary.size(); ++i) {
            const auto& word = dictionary[i];
            int node = 0;
            
            for (char ch : word) {
                int index = ch - 'a';
                
                if (trie[node].nodes[index] == -1) {
                    trie[node].nodes[index] = trie.size();
                    trie.emplace_back();
                }
                
                node = trie[node].nodes[index];
            }
            
            trie[node].word = i;
        }
        
        size_t pos = 0;
        size_t node = 0;
        size_t begin = 0;
        std::string res;
        res.reserve(sentence.size());
        
        while (pos < sentence.size()) {
            int index = sentence[pos] - 'a';
            
            if (sentence[pos] == ' ' || trie[node].nodes[index] == -1) {
                pos = move_forward(pos, sentence);
                add(sentence.substr(begin, pos - begin), res);
                ++pos;
                begin = pos;
                node = 0;
                continue;
            }
            
            node = trie[node].nodes[index];
            
            if (trie[node].word != -1) {
                add(dictionary[trie[node].word], res);
                pos = move_forward(pos, sentence) + 1;
                node = 0;
                begin = pos;
                continue;
            }
            
            ++pos;
        }
        
        if (begin < pos) {
            add(sentence.substr(begin, pos - begin), res);
        }
        
        return res;
    }
};