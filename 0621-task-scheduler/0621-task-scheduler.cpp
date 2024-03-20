class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> data(26, 0);
        for (char ch : tasks) {
            ++data[ch - 'A'];
        }
        
        std::priority_queue<int> task_queue;
        for (auto task : data) {
            if (task > 0) {
                task_queue.emplace(task);
            }
        }
        
        auto cmp = [](const std::pair<int, int>& p1, const std::pair<int, int>& p2){
            return p1.first > p2.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> time_queue(cmp);
        int time = 0;
        int res = 0;
        
        while (true) {
            while (!time_queue.empty() && time_queue.top().first <= time) {
                task_queue.emplace(time_queue.top().second);
                time_queue.pop();
            }
            
            if (task_queue.empty() && time_queue.empty()) {
                break;
            }
            
            if (task_queue.empty()) {
                res += time_queue.top().first - time;
                time = time_queue.top().first;
                continue;
            }
            
            if (task_queue.top() > 1) {
                time_queue.emplace(time + n + 1, task_queue.top() - 1);
            }
            
            ++res;
            ++time;
            task_queue.pop();
        }
        
        return res;
 
    }
};


/*

["A","B","A"]
2
["A","B"]
2
["A","A","A","B","B","B"]
2
["A","C","A","B","D","B"]
1
["A","A","A", "B","B","B"]
3

*/