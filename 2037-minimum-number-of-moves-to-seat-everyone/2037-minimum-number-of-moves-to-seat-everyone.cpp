class Solution {
public:
    inline size_t move_forward(const std::vector<int>& data, size_t index) {
        while (index < data.size() && data[index] == 0) {
            ++index;
        }
        return index;
    }
    
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::vector<int> data_seats(101, 0);
        for (int val : seats) {
            ++data_seats[val];
        }
        
        std::vector<int> data_students(101, 0);
        for (int val : students) {
            ++data_students[val];
        }
        
        size_t students_index = move_forward(data_students, 0);
        size_t seats_index = move_forward(data_seats, 0);
        int res = 0;

        while (students_index < data_students.size()) {
            res += seats_index > students_index ? seats_index - students_index : students_index - seats_index;
            --data_students[students_index];
            --data_seats[seats_index];
            
            students_index = move_forward(data_students, students_index);
            seats_index = move_forward(data_seats, seats_index);
        }
        
        return res;
    }
};