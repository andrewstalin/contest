struct Item{
    std::vector<int> persons;
    int pos{ 0 };
    
    Item() {}
};

class Solution {
public:
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[2] < v2[2];
        });
        
        std::vector<Item> data(n);
        
        std::vector<bool> visited(n, false);
        visited[0] = true;
        visited[firstPerson] = true;
        
        std::vector<int> res;
        res.reserve(n);
        res.emplace_back(0);
        res.emplace_back(firstPerson);
        
        int index = 0;
        
        std::vector<int> stack(2*n, 0);
        int stackp = -1;
        std::vector<bool> instack(n, false);
        
        while (index < meetings.size()) {
            int time = meetings[index][2];
            int begin = index;
            
            if (time == 16) {
                int stop = 1;
            }
            
            while (index < meetings.size() && meetings[index][2] == time) {
                data[meetings[index][0]].persons.emplace_back(meetings[index][1]);
                data[meetings[index][1]].persons.emplace_back(meetings[index][0]);
                
                if (visited[meetings[index][0]] && !instack[meetings[index][0]]) {
                    ++stackp;
                    stack[stackp] = meetings[index][0];
                    instack[meetings[index][0]] = true;
                }
                
                if (visited[meetings[index][1]] && !instack[meetings[index][1]]) {
                    ++stackp;
                    stack[stackp] = meetings[index][1];
                    instack[meetings[index][1]] = true;
                }
                
                ++index;
            }
            
            while (stackp >= 0) {
                auto p = stack[stackp];
                instack[p] = false;
                --stackp;
                
                for (int i = data[p].pos; i < data[p].persons.size(); ++i) {
                    if (!visited[data[p].persons[i]]) {
                        visited[data[p].persons[i]] = true;
                        ++stackp;
                        stack[stackp] = data[p].persons[i];
                        res.emplace_back(data[p].persons[i]);
                    }
                }
            }

            if (index < meetings.size()) {
                for (int i = begin; i < index; ++i) {
                    data[meetings[i][0]].pos = data[meetings[i][0]].persons.size();
                    data[meetings[i][1]].pos = data[meetings[i][1]].persons.size();
                }
            }
        }
        
        return res;
    }
};