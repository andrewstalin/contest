class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {        
        std::sort(deck.begin(), deck.end());
        
        if (deck.size() < 4) {
            if (deck.size() == 3) {
                std::swap(deck[1], deck[2]);
            }
            
            return deck;
        }
         
        std::vector<int> res(deck.size(), 0);
        
        std::queue<int> queue;
        for (int i = 0; i < deck.size(); ++i) {
            queue.emplace(i);
        }
        
        int index = 0;
        while (!queue.empty()) {
            int v = queue.front();
            queue.pop();
            
            res[v] = deck[index];
            ++index;
            
            if (!queue.empty()) {
                queue.emplace(queue.front());
                queue.pop();
            }
        }
        
        return res;
    }
};