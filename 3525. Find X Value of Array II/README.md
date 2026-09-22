# 3525. Find X Value of Array II

**Difficulty:** `Hard`  
**Tags:** `Array`, `Math`, `Segment Tree`

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

[LeetCode — 3525. Find X Value of Array II](https://leetcode.com/problems/find-x-value-of-array-ii/)

---

## Problem Summary

The problem involves an array of positive integers and a modulus k. It defines an 'x-value' as the number of ways to remove a suffix from the array such that the product of the remaining elements leaves a remainder of x when divided by k. The task is to process multiple queries, each involving an update to a specific array element and a request to calculate the x-value for a given x and a starting index, effectively querying the number of valid prefixes for a specific remainder.

---

## Examples

_No examples provided._

---

## Intuition

The solution utilizes a segment tree to efficiently store and retrieve information about the array's state. Each node in the tree contains the product of the elements in its segment and a frequency count for each possible remainder (0 to k-1). This allows for quick calculation of the product of any subarray and the number of prefixes that yield a specific remainder, which is the core requirement for determining the x-value.

---

## Approach

1. Build a segment tree where each node stores the product of its segment and a count of how many prefixes within that segment result in each remainder (0 to k-1).
2. For each query, first update the specified array element in the segment tree.
3. Then, query the segment tree for the subarray starting at the given index and ending at the end of the array.
4. The result of this query provides the count of prefixes that have a product remainder equal to the specified x, which is the answer for that query.

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n log n + q log n)` — The initial build of the segment tree takes O(n log n) time. Each query involves an update (O(log n)) and a lookup (O(log n)), making the total time complexity for q queries O(n log n + q log n). |
| **Space** | `O(n * k)` — The segment tree requires space for approximately 4n nodes, each storing a product and a frequency array of size k. This results in a space complexity of O(n * k). |

---

## Code (C++)

```cpp
class Solution {
public:

    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;

        // Product of the complete segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Prefixes that contain all of left
        // and then continue into right
        for (int r = 0; r < k; r++) {
            int newRemainder = (left.prod * r) % k;

            res.cnt[newRemainder] += right.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {
            int rem = value % k;

            tree[node] = Node();

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Complete segment is inside query
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely in left
        if (qr <= mid) {
            return query(
                node * 2,
                l,
                mid,
                ql,
                qr
            );
        }

        // Completely in right
        if (ql > mid) {
            return query(
                node * 2 + 1,
                mid + 1,
                r,
                ql,
                qr
            );
        }

        // Split between left and right
        Node left = query(
            node * 2,
            l,
            mid,
            ql,
            qr
        );

        Node right = query(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr
        );

        return mergeNodes(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        // Build segment tree
        build(nums, 1, 0, n - 1);

        vector<int> answer;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Step 1: Update nums[index]
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // Step 2: Query [start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            // Step 3: Number of prefixes
            // having product remainder x
            answer.push_back(res.cnt[x]);
        }

        return answer;
    }
};
```

---

## Key Takeaways

- Segment trees are a powerful data structure for efficiently answering range queries on arrays, especially when the query involves a commutative operation like multiplication.
- By storing frequency counts for remainders, the tree can quickly determine the number of valid prefixes for a specific modulus condition, which is crucial for this problem's definition of the x-value.
