# 1606. Find Servers That Handled Most Number of Requests

**Difficulty:** `Hard`  
**Tags:** `Array`, `Heap (Priority Queue)`, `Simulation`, `Ordered Set`

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

[LeetCode — 1606. Find Servers That Handled Most Number of Requests](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)

---

## Problem Summary

You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:  
- The ith (0-indexed) request arrives.

---

## Examples

### Example 1
**Input:** `k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3]`  
**Output:** `[1]`  
**Explanation:**
- All of the servers start out available.
- The first 3 requests are handled by the first 3 servers in order.
- Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
- Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
- Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.

### Example 2
**Input:** `k = 3, arrival = [1,2,3,4], load = [1,2,1,2]`  
**Output:** `[0]`  
**Explanation:**
- The first 3 requests are handled by first 3 servers.
- Request 3 comes in. It is handled by server 0 since the server is available.
- Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.

### Example 3
**Input:** `k = 3, arrival = [1,2,3], load = [10,12,11]`  
**Output:** `[0,1,2]`  
**Explanation:**
- Each server handles a single request, so they are all considered the busiest.

---

## Intuition

The problem revolves around array, heap (priority queue), simulation, ordered set. The key observation is that only the structure imposed by the constraints matters — once that pattern is identified, the solution follows directly from it.

---

## Approach

1. Translate the problem rules into the exact operations shown in the accepted code below.
2. Handle the edge cases implied by the constraints.
3. Return the result required by the problem statement.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n^2)` — nested iteration |
| **Space** | `O(n)` — extra storage proportional to input |

---

## Code (C++)

```cpp
class Solution {
public:
    typedef pair<int, int> P; //{finishTime, serverId}

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i = 0; i < k; i++) {
            available_servers.insert(i); //k * log(k)
        }

        priority_queue<P, vector<P>, greater<P>> busyServers;

        vector<int> countRequests(k, 0);

        //Total requests = n
        //T.C = n * log(k)
        for(int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            while(!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;

                busyServers.pop();

                available_servers.insert(server);
            }

            int target = i%k;

            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()) { //wrap around
                it = available_servers.begin();
            }

            if(available_servers.empty()) {
                continue; //no servers available. Drop the current request
            }

            int targetServer = *it;

            available_servers.erase(it); //because this server is going to be busy

            busyServers.push({time + load[i], targetServer});

            countRequests[targetServer]++;

        }

        int maxNumberOfRequests = *max_element(begin(countRequests), end(countRequests)); //O(k)

        vector<int> result;

        for(int i = 0; i < k; i++) {
            if(countRequests[i] == maxNumberOfRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- Identify the invariant the problem is really asking about before coding.
- Array, Heap (Priority Queue), Simulation, Ordered Set patterns often reduce an apparently complex problem to a few simple rules.
