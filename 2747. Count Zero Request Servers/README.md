# 2747. Count Zero Request Servers

**Difficulty:** `Medium`  
**Tags:** `Array`, `Hash Table`, `Sliding Window`, `Sorting`

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

[LeetCode — 2747. Count Zero Request Servers](https://leetcode.com/problems/count-zero-request-servers/)

---

## Problem Summary

The problem involves tracking server activity over time to determine periods of inactivity. Given a list of request logs and a set of query times, the goal is to calculate how many servers have not received any requests within a specific time window (from `queries[i] - x` to `queries[i]`) for each query. The solution efficiently processes these queries by sorting the data and using a sliding window approach to count active servers.

---

## Examples

### Example 1
**Input:** `n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]`  
**Output:** `[1,2]`  
**Explanation:**
- For queries[0]: The servers with ids 1 and 2 get requests in the duration of [5, 10]. Hence, only server 3 gets zero requests.
- For queries[1]: Only the server with id 2 gets a request in duration of [6,11]. Hence, the servers with ids 1 and 3 are the only servers that do not receive any requests during that time period.

### Example 2
**Input:** `n = 3, logs = [[2,4],[2,1],[1,2],[3,1]], x = 2, queries = [3,4]`  
**Output:** `[0,1]`  
**Explanation:**
- For queries[0]: All servers get at least one request in the duration of [1, 3].
- For queries[1]: Only server with id 3 gets no request in the duration [2,4].

---

## Intuition

The core insight is to leverage the sorted nature of the data to perform efficient lookups. By sorting both the request logs and the queries by time, the solution can use a 'sliding window' technique. This allows it to quickly determine which servers are active (have received requests) within the current time window for each query, without having to re-scan the entire log for every single query.

---

## Approach

1. Sort the request logs by time to enable efficient linear scanning.
2. Sort the queries by time to process them in a way that minimizes redundant calculations.
3. Initialize a frequency counter for each server and a variable to track the number of active servers.
4. For each query, use a sliding window to include all requests up to the query time and exclude requests older than the window's start.
5. Calculate the number of inactive servers by subtracting the count of active servers from the total number of servers.
6. Store the result for the current query and move to the next.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O((n + q) log(n + q))` — The dominant factor is the initial sorting of the logs and queries, which takes O(n log n) and O(q log q) respectively. The subsequent processing of queries with the sliding window is linear relative to the data size, resulting in an overall complexity of O((n + q) log(n + q)). |
| **Space** | `O(n + q)` — The solution requires extra space for the frequency array (size n) and the sorted queries list (size q). The original logs and queries are also stored, but the additional data structures are what determine the asymptotic space complexity. |

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        // Store query time and original index
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        // Sort queries by time
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> answer(q);

        // Frequency of requests for each server
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int activeServers = 0;

        // Process queries in sorted order
        for (auto [time, index] : sortedQueries) {

            int start = time - x;

            // Add logs with time <= query time
            while (right < logs.size() &&
                   logs[right][1] <= time) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    activeServers++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs with time < query - x
            while (left < right &&
                   logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Servers with zero requests
            answer[index] = n - activeServers;
        }

        return answer;
    }
};
```

---

## Key Takeaways

- Sorting input data by time is a critical step for efficient interval-based queries.
- The sliding window pattern is highly effective for tracking dynamic sets of active elements over time.
- Maintaining a frequency counter allows for constant-time updates to the state of the system as the window slides.
