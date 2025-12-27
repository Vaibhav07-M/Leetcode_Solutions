class Solution {
public:
    int mostBooked(int roomCount, vector<vector<int>>& schedule) {
        sort(schedule.begin(), schedule.end());

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int roomId = 0; roomId < roomCount; roomId++) {
            availableRooms.push(roomId);
        }

        priority_queue<pair<long long, int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> reservedRooms;

        vector<long long> meetingCounter(roomCount, 0);

        for (auto &meeting : schedule) {
            long long startTime = meeting[0];
            long long endTime   = meeting[1];
            long long duration  = endTime - startTime;

            while (!reservedRooms.empty() && reservedRooms.top().first <= startTime) {
                auto [freeTime, freedRoom] = reservedRooms.top();
                reservedRooms.pop();
                availableRooms.push(freedRoom);
            }

            if (!availableRooms.empty()) {
                int selectedRoom = availableRooms.top();
                availableRooms.pop();
                reservedRooms.push({endTime, selectedRoom});
                meetingCounter[selectedRoom]++;
            }
            else {
                auto [nextFreeTime, occupiedRoom] = reservedRooms.top();
                reservedRooms.pop();

                long long delayedEnd = nextFreeTime + duration;
                reservedRooms.push({delayedEnd, occupiedRoom});
                meetingCounter[occupiedRoom]++;
            }
        }

        int bestRoom = 0;
        for (int room = 1; room < roomCount; room++) {
            if (meetingCounter[room] > meetingCounter[bestRoom]) {
                bestRoom = room;
            }
        }

        return bestRoom;
    }
};
