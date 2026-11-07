# 1882. Process Tasks Using Servers

**Difficulty:** `Medium`  
**Tags:** `Array`, `Heap (Priority Queue)`

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

[LeetCode — 1882. Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/)

---

## Problem Summary

The problem involves assigning a series of tasks to a set of servers, each with a specific weight. The goal is to minimize the total processing time by assigning tasks to the server with the lowest weight that is currently free. If multiple servers have the same weight, the one with the lower index is preferred. The solution must output the index of the server assigned to each task.

---

## Examples

### Example 1
**Input:** `servers = [3,3,2], tasks = [1,2,3,2,1,2]`  
**Output:** `[2,2,0,2,1,2]`  
**Explanation:**
- Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 2 until second 1.
- At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
- At second 2, task 2 is added and processed using server 0 until second 5.
- At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
- At second 4, task 4 is added and processed using server 1 until second 5.
- At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.

### Example 2
**Input:** `servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]`  
**Output:** `[1,4,1,4,1,3,2]`  
**Explanation:**
- Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 1 until second 2.
- At second 1, task 1 is added and processed using server 4 until second 2.
- At second 2, servers 1 and 4 become free. Task 2 is added and processed using server 1 until second 4.
- At second 3, task 3 is added and processed using server 4 until second 7.
- At second 4, server 1 becomes free. Task 4 is added and processed using server 1 until second 9.
- At second 5, task 5 is added and processed using server 3 until second 7.
- At second 6, task 6 is added and processed using server 2 until second 7.

---

## Intuition

The core insight is to use two priority queues to manage the state of the servers. One queue tracks the free servers (sorted by weight and index), and the other tracks the busy servers (sorted by their finish time). By iterating through the tasks, we can efficiently move servers between these queues based on their availability, ensuring that tasks are always assigned to the most optimal server.

---

## Approach

1. Initialize two priority queues: one for free servers (sorted by weight and index) and one for busy servers (sorted by finish time).
2. Iterate through the list of tasks. For each task, check the busy servers queue to see if any servers have finished their previous tasks and are now free (i.e., their finish time is less than or equal to the current task index). If so, move them to the free servers queue.
3. Assign the current task to the server at the top of the free servers queue (the one with the lowest weight and index).
4. Update the result array with the index of the assigned server and add the server to the busy servers queue with its new finish time (current time + task duration).
5. Repeat this process until all tasks have been assigned.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(m log n)` — The algorithm iterates through m tasks. For each task, it performs operations on the priority queues, which have a time complexity of O(log n) for insertion and deletion. Therefore, the overall time complexity is O(m log n). |
| **Space** | `O(n)` — The space complexity is determined by the storage of the two priority queues, which hold up to n servers each. The result array also stores m integers, but the dominant factor is the queue storage relative to the number of servers. |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef pair<int, int> P; //wt, idx
    typedef tuple<long, int, int> T; //finTime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        //free servers (wt, idx)
        priority_queue<P, vector<P>, greater<P>> freeServers;

        ///Busy servers {fintTime, wt, idx}
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i = 0; i < n; i++) { //n
            freeServers.push({servers[i], i}); //log(n)
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++) { //
            //Move busy servers to free servers if they are free by ith time
            //Busy Servers ---> Free Servers
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }

            //Free Servers ---> Busy Server

            if(freeServers.empty()) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({finTime + tasks[i], wt, idx});
            } else { //Free Servers ---> Busy Server //(all servers move to busy for all tasks)
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }
        }
        //Tota m tasks * log(n) push/pop = Overall time compelxity of this entire for loop

        return result;
    }
};
```

---

## Key Takeaways

- This problem demonstrates the efficient use of priority queues to manage resource allocation (servers) based on specific criteria (weight and availability).
- The solution effectively simulates a discrete-time event system where resources become available at specific times, requiring careful tracking of state transitions.
