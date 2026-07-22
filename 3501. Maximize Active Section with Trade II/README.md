# 3501. Maximize Active Section with Trade II

**Difficulty:** `Hard`  
**Tags:** `String`, `Binary Search`, `Segment Tree`, `Greedy`, `Run-Length Encoding`

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

[LeetCode – 3501. Maximize Active Section with Trade II](https://leetcode.com/problems/maximize-active-section-with-trade-ii/)

---

## Problem Summary

Given a binary string `s` and multiple substring queries `[l, r]`, determine the maximum number of active (`'1'`) sections obtainable in each queried substring after performing **at most one valid trade**.

For every query:

1. Treat the substring as augmented with `'1'` at both ends.
2. Convert one eligible `'1'` block into `'0'`s.
3. Then convert one eligible `'0'` block into `'1'`s.

The queries are independent, and the answer for each query is the maximum number of active sections after the optimal trade. :contentReference[oaicite:0]{index=0}

---

## Examples

### Example 1

**Input**

```text
s = "01"
queries = [[0,1]]
```

**Output**

```text
[1]
```

---

### Example 2

**Input**

```text
s = "0100"
queries = [[0,3],[0,2],[1,3],[2,3]]
```

**Output**

```text
[4,3,1,1]
```

---

### Example 3

**Input**

```text
s = "1000100"
queries = [[1,5],[0,6],[0,4]]
```

**Output**

```text
[6,7,2]
```

---

## Intuition

Instead of processing every query character by character:

- Compress all zero blocks.
- Store their lengths.
- Observe that every valid trade depends only on **two neighboring zero blocks**.
- Precompute adjacent block sums.
- Build a Segment Tree over these pair sums so each query can efficiently obtain the maximum candidate inside its range.

Binary search quickly identifies which zero blocks intersect a query.

---

## Approach

1. Count the total number of active sections.
2. Extract every contiguous zero block.
3. Store:
   - starting index,
   - ending index,
   - block length.
4. Compute the sum of every adjacent pair of zero blocks.
5. Build a Segment Tree over these pair sums for Range Maximum Queries.
6. For each query:
   - Locate the first and last zero blocks intersecting the substring using binary search.
   - Handle:
     - fewer than two zero blocks,
     - exactly two blocks,
     - multiple blocks.
   - Query the Segment Tree for the best interior pair.
7. Add the maximum obtainable gain to the original number of active sections.

---

## Complexity

| Metric | Complexity |
|---------|------------|
| **Preprocessing** | `O(n)` |
| **Segment Tree Build** | `O(n)` |
| **Each Query** | `O(log n)` |
| **Space** | `O(n)` |

---

## Code (C++)

```cpp
void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start)
        return INT_MIN;

    if (l >= start && r <= end)
        return segmentTree[i];

    int mid = l + (r - l) / 2;

    return max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int activeCount = count(begin(s), end(s), '1');

        vector<int> blockStart;
        vector<int> blockEnd;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;
                blockStart.push_back(start);
                blockEnd.push_back(i - 1);
            } else {
                i++;
            }
        }

        int m = blockStart.size();

        if (m < 2)
            return vector<int>(queries.size(), activeCount);

        vector<int> blockSize(m);
        for (int i = 0; i < m; i++)
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;

        int N = blockSize.size() - 1;

        vector<int> pairSum(N);
        for (int i = 0; i < N; i++)
            pairSum[i] = blockSize[i] + blockSize[i + 1];

        int* st = constructST(pairSum.data(), N);

        vector<int> result;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int low = lower_bound(begin(blockEnd), end(blockEnd), l) - begin(blockEnd);
            int high = upper_bound(begin(blockStart), end(blockStart), r) - begin(blockStart) - 1;

            int maxPairSum = 0;

            if (low < high) {
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1;
                int lastLen = min(blockEnd[high], r) - blockStart[high] + 1;

                if (high - low == 1) {
                    maxPairSum = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low + 1];
                    int pair2 = blockSize[high - 1] + lastLen;
                    int RMQMaxPairSum = RMQ(st, N, low + 1, high - 2);

                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            }

            result.push_back(maxPairSum + activeCount);
        }

        return result;
    }
};
```

---

## Key Takeaways

- Compress consecutive zero blocks using **Run-Length Encoding**.
- Binary search quickly locates the zero blocks intersecting each query.
- Adjacent zero-block sums capture every possible trade candidate.
- A **Segment Tree** supports fast Range Maximum Queries over these pair sums.
- Preprocessing is linear, and every query is answered efficiently in **O(log n)** time.