# 2402. Meeting Rooms III

**Difficulty:** `Hard`  
**Tags:** `Array`, `Heap (Priority Queue)`, `Sorting`, `Simulation`

---

## Table of Contents
- [Problem Link](#problem-link)
- [Problem Summary](#problem-summary)
- [Examples](#examples)
- [Intuition](#intuition)
- [Approach](#approach)
- [Complexity](#complexity)
- [Code (C++)](#code-c)
- [Key Takeaways](#key-takeaways)

---

## Problem Link

[LeetCode — 2402. Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/)

---

## Problem Summary

You are given `n` rooms numbered from `0` to `n-1` and a 2D array `meetings` where `meetings[i] = [start_i, end_i]` represents a meeting during the half-closed interval `[start_i, end_i)`.

**Allocation Rules:**
1. Each meeting takes the **unused room with the lowest number**
2. If no rooms available, the meeting is **delayed** until a room frees up (keeping same duration)
3. When a room becomes free, meetings with **earlier original start times** get priority

Return the **room number that held the most meetings**. If there's a tie, return the **lowest numbered room**.

---

## Examples

### Example 1
**Input:** `n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]`  
**Output:** `0`  
**Explanation:**
- Time 0: Meeting 1 starts in room 0 [0,10)
- Time 1: Meeting 2 starts in room 1 [1,5)
- Time 2: Meeting 3 delayed (both rooms busy)
- Time 5: Room 1 frees, Meeting 3 starts [5,10)
- Time 10: Both rooms free, Meeting 4 starts in room 0 [10,11)
- Result: Both rooms held 2 meetings, return room 0

### Example 2
**Input:** `n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]`  
**Output:** `1`  
**Explanation:**
- Room 0 held 1 meeting
- Rooms 1 and 2 each held 2 meetings
- Return room 1 (lowest number with max meetings)

---

## Intuition

This problem simulates a room scheduling system where we need to:
1. Track which rooms are available
2. Track when occupied rooms will become free
3. Handle meeting delays when all rooms are busy
4. Count meetings per room

Using **two priority queues** (heaps) elegantly solves this:
- One heap for **available rooms** (min-heap by room number)
- One heap for **occupied rooms** (min-heap by end time, then room number)

Processing meetings in chronological order allows us to simulate the scheduling efficiently.

---

## Approach

1. **Sort meetings by start time** to process them chronologically

2. **Initialize two heaps:**
   - `availableRooms`: min-heap of free room numbers
   - `reservedRooms`: min-heap of `(endTime, roomNumber)` pairs

3. **For each meeting:**
   - **Free up rooms:** Pop from `reservedRooms` all rooms that finished by current start time
   - **If room available:** 
     - Assign lowest numbered available room
     - Schedule meeting with original time
   - **If all rooms busy:**
     - Take the room that frees earliest
     - Delay meeting to start when that room becomes free
     - Keep same duration
   - Increment meeting count for the assigned room

4. **Find room with maximum meetings** (return lowest room number on tie)

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m log m + m log n)` where m = meetings, n = rooms |
| **Space** | `O(n)` for the heaps and counters |

**Breakdown:**
- Sorting: `O(m log m)`
- Each meeting: up to `O(log n)` heap operations
- Total: `O(m log m + m log n)`

---

## Code (C++)

```cpp
class Solution {
public:
    int mostBooked(int roomCount, vector<vector<int>>& schedule) {
        sort(schedule.begin(), schedule.end());

        // Min-heap for available rooms (by room number)
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int roomId = 0; roomId < roomCount; roomId++) {
            availableRooms.push(roomId);
        }

        // Min-heap for occupied rooms (by end time, then room number)
        priority_queue<pair<long long, int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> reservedRooms;

        vector<long long> meetingCounter(roomCount, 0);

        for (auto &meeting : schedule) {
            long long startTime = meeting[0];
            long long endTime   = meeting[1];
            long long duration  = endTime - startTime;

            // Free up rooms that finished by current start time
            while (!reservedRooms.empty() && reservedRooms.top().first <= startTime) {
                auto [freeTime, freedRoom] = reservedRooms.top();
                reservedRooms.pop();
                availableRooms.push(freedRoom);
            }

            // Assign to available room
            if (!availableRooms.empty()) {
                int selectedRoom = availableRooms.top();
                availableRooms.pop();
                reservedRooms.push({endTime, selectedRoom});
                meetingCounter[selectedRoom]++;
            }
            // No room available - delay meeting
            else {
                auto [nextFreeTime, occupiedRoom] = reservedRooms.top();
                reservedRooms.pop();

                long long delayedEnd = nextFreeTime + duration;
                reservedRooms.push({delayedEnd, occupiedRoom});
                meetingCounter[occupiedRoom]++;
            }
        }

        // Find room with most meetings (lowest number on tie)
        int bestRoom = 0;
        for (int room = 1; room < roomCount; room++) {
            if (meetingCounter[room] > meetingCounter[bestRoom]) {
                bestRoom = room;
            }
        }

        return bestRoom;
    }
};
```

---

## Key Takeaways

- Use dual priority queues to efficiently track available and occupied resources.
- Sorting events chronologically simplifies simulation problems.
- Heap operations provide optimal performance for dynamic min/max queries.
