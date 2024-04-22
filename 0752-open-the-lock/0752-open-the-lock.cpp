
struct Item {
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    uint8_t b4;
    
    Item(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4): b1(b1), b2(b2), b3(b3), b4(b4) {}
    
    uint8_t& operator[](int index) {
        if (index == 0) {
            return b1;
        } else if (index == 1) {
            return b2;
        } else if (index == 2) {
            return b3;
        } else {
            return b4;
        }
    }
    
    bool operator==(const Item& other) const {
        return b1 == other.b1 && b2 == other.b2 && b3 == other.b3 && b4 == other.b4;
    };
    
    std::string to_string() const {
        std::string res;
        res.push_back('0' + b1);
        res.push_back('0' + b2);
        res.push_back('0' + b3);
        res.push_back('0' + b4);
        return res;
    }
};

struct Turn {
    Item item;
    int count;
    
    Turn(const Item& item, int count): item(item), count(count) {}
};

namespace std {
    template<> struct hash<Item> {
        std::size_t operator()(const Item& item) const noexcept {
            size_t res = item.b4;
            res <<= 8;
            res |= item.b3;
            res <<= 8;
            res |= item.b2;
            res <<= 8;
            res |= item.b1;
            return res;
        }
    };
}

class Solution {
public:
    inline Item to_item(const std::string& s) {
        return Item{ static_cast<uint8_t>(s[0] - '0'), static_cast<uint8_t>(s[1] - '0'), static_cast<uint8_t>(s[2] - '0'), static_cast<uint8_t>(s[3] - '0') };
    }
    
    inline static bool func(const Turn& turn, int digit, bool increase, std::queue<Turn>& queue, std::unordered_set<Item>& processed, const std::unordered_set<Item>& lock, const Item& end) {
        auto item = turn.item;
        
        if (increase) {
            ++item[digit];
            item[digit] %= 10;
        } else {
            if (item[digit] == 0) {
                item[digit] = 9;
            } else {
                --item[digit];
            }
        }
         
        // std::cout << item.to_string() << std::endl;
        
        if (processed.find(item) != processed.end() || lock.find(item) != lock.end()) {
            return false;    
        }
        
        if (item == end) {
            return true;
        }

        processed.emplace(item);
        queue.emplace(item, turn.count);        
        return false;
    }
    
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        
        std::unordered_set<Item> lock(deadends.size());

        for (int i = 0; i < deadends.size(); ++i) {
            if (deadends[i] == "0000") {
                return -1;
            }
            
            lock.emplace(to_item(deadends[i]));
        }
        
        auto end = to_item(target);
        
        std::queue<Turn> queue;
        queue.emplace(Item(0, 0, 0, 0), 0);
        
        std::unordered_set<Item> processed(10000);
        processed.emplace(queue.front().item);
        
        while(!queue.empty()) {
            auto turn = queue.front();
            queue.pop();
            
            ++turn.count;
            
            for (int i = 0; i < 4; ++i) {
                if (func(turn, i, true, queue, processed, lock, end)) {
                    return turn.count;
                }
            }
            
            for (int i = 0; i < 4; ++i) {
                if (func(turn, i, false, queue, processed, lock, end)) {
                    return turn.count;
                }
            }
        }
        
        return -1;
    }
};