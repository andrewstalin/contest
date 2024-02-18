struct MeetingRoom {
    int id;
    int used;
    
    MeetingRoom(int id, int used): id(id), used(used) {}
};

struct OccupidRoom {
    int id;
    int used;
    uint64_t release_time;
    
    OccupidRoom(int id, int used, uint64_t release_time): id(id), used(used), release_time(release_time) {}
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[0] < v2[0];
        });
        
        auto meeting_room_cmp = [](const MeetingRoom& r1, const MeetingRoom& r2){
            return r1.id > r2.id;
        };
        std::priority_queue<MeetingRoom, std::vector<MeetingRoom>, decltype(meeting_room_cmp)> rooms(meeting_room_cmp);
        
        for (int i = 0; i < n; ++i) {
            rooms.emplace(i, 0);
        }
        
        auto occupid_rooms_cmp = [](const OccupidRoom& r1, const OccupidRoom& r2){
            return r1.release_time == r2.release_time ? r1.id > r2.id : r1.release_time > r2.release_time;
        };
        std::priority_queue<OccupidRoom, std::vector<OccupidRoom>, decltype(occupid_rooms_cmp)> occupid_rooms(occupid_rooms_cmp);
        
        int max = 0;
        int id = INT32_MAX;
        uint64_t time = 0;
        int index = 0;
        
        while (index < meetings.size()) {
            const auto& meeting = meetings[index];
            if (time < meeting[0]) {
                time = meeting[0];
            }
            
            while (!occupid_rooms.empty() && occupid_rooms.top().release_time<= time) {
                rooms.emplace(occupid_rooms.top().id, occupid_rooms.top().used);
                occupid_rooms.pop();
            }
            
            if (!rooms.empty()) {
                auto r = rooms.top();
                rooms.pop();
                
                ++r.used;
                
                if (r.used > max || (r.used == max && r.id < id)) {
                    id = r.id;
                    max = r.used;
                }
                
                occupid_rooms.emplace(r.id, r.used, time + (meeting[1] - meeting[0]));
                ++index;
                continue;
            }

            time = occupid_rooms.top().release_time;
        }
        
        return id;
    }
};