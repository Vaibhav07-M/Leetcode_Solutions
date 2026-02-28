# 3666. Minimum Operations to Equalize Binary String

**Difficulty:** `Hard`  
**Tags:** `String, BFS, Math, Greedy`

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

[LeetCode — 3666. Minimum Operations to Equalize Binary String](https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/)

---

## Problem Summary

You are given a binary string `s`, and an integer `k`.

In one operation, you must choose exactly `k` different indices and flip each `'0'` to `'1'` and each `'1'` to `'0'`.

Return the **minimum number of operations** required to make all characters in the string equal to `'1'`. If it is not possible, return `-1`.

---

## Examples

### Example 1
**Input:** `s = "110", k = 1`  
**Output:** `1`  
**Explanation:**  
There is one `'0'` in s.  
Since k = 1, we can flip it directly in one operation.

### Example 2
**Input:** `s = "0101", k = 3`  
**Output:** `2`  
**Explanation:**  
One optimal set of operations choosing k = 3 indices in each operation is:
- Operation 1: Flip indices [0, 1, 3]. s changes from `"0101"` to `"1000"`.
- Operation 2: Flip indices [1, 2, 3]. s changes from `"1000"` to `"1111"`.

Thus, the minimum number of operations is 2.

### Example 3
**Input:** `s = "101", k = 2`  
**Output:** `-1`  
**Explanation:**  
Since k = 2 and s has only one `'0'`, it is impossible to flip exactly k indices to make all `'1'`. Hence, the answer is -1.

---

## Intuition

This is a state-space search problem where we need to find the minimum operations to reach a target state (all 1s).

**Key observations:**
- We must flip exactly k indices in each operation
- Each flip toggles the bit: `'0'` ↔ `'1'`
- Goal: Reduce the number of zeros to 0
- State: Number of zeros in the current string
- Transition: Each operation changes the zero count based on how many 0s and 1s we flip

**Critical insight:**
- If we have `z` zeros currently, we can flip `x` zeros and `k-x` ones
- After flipping: zeros become ones, ones become zeros
- New zero count = `z - x + (k - x) = z + k - 2x`
- Where `x` ranges from `max(0, k - (n - z))` to `min(k, z)`
- This means new zero count can range from `z + k - 2*min(k, z)` to `z + k - 2*max(0, k-n+z)`

**BFS approach:**
- Start with initial zero count
- For each state, explore all reachable states (new zero counts)
- Use BFS to find shortest path to 0 zeros
- Optimization: Separate even and odd counts since parity changes predictably

**Impossibility condition:**
- If we can never reach 0 zeros through valid transitions
- Happens when the reachable states don't include 0

---

## Approach

### Solution 1: BFS with State Optimization

1. **Count initial zeros**: If already 0, return 0
2. **Initialize BFS**:
   - Track visited states (zero counts)
   - Separate even/odd sets for efficient range queries
   - Queue starts with initial zero count
3. **For each state (zero count z)**:
   - Calculate range of reachable new zero counts
   - Formula: new_z ∈ [z + k - 2*min(k,z), z + k - 2*max(0, k-n+z)]
   - All new states have same parity (even or odd)
4. **Process reachable states**:
   - Use `lower_bound` to find states in range
   - Mark as visited and add to queue
   - If we reach 0, return the operation count
5. **Return -1** if 0 is unreachable

**Optimization tricks:**
- Use sets to track unvisited states by parity
- Use `lower_bound` for efficient range processing
- Erase processed states to avoid revisiting

### Solution 2: Mathematical Analysis

Analyze the reachability based on GCD and parity constraints (more complex mathematical approach).

---

## Complexity

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n² log n)` — BFS explores O(n) states, each processes O(n) range with O(log n) set operations |
| **Space** | `O(n)` — store operations array and sets for even/odd counts |

**Note:** Practical performance is much better due to early termination and state pruning.

---

## Code (C++)

### Solution 1: BFS with Parity Optimization (Optimal)

```cpp
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        
        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }
        
        if(startZeros == 0) {
            return 0; // no operations required
        }
        
        vector<int> operations(n + 1, -1);
        // operations[z] = min operations required to reach state with z zeros
        
        set<int> evenSet;
        set<int> oddSet;
        
        for(int count = 0; count <= n; count++) {
            if(count % 2 == 0) {
                evenSet.insert(count);
            } else {
                oddSet.insert(count);
            }
        }
        
        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;
        if(startZeros % 2 == 0) {
            evenSet.erase(startZeros);
        } else {
            oddSet.erase(startZeros);
        }
        
        while(!que.empty()) {
            int z = que.front();
            que.pop();
            
            // Calculate range of new zero counts
            int min_new_z = z + k - 2 * min(k, z);
            int max_new_z = z + k - 2 * max(0, k - n + z);
            
            set<int> &currSet = (min_new_z % 2 == 0) ? evenSet : oddSet;
            
            auto it = currSet.lower_bound(min_new_z);
            
            while(it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;
                
                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;
                    
                    if(newZ == 0) {
                        return operations[newZ];
                    }
                    
                    que.push(newZ);
                }
                
                it = currSet.erase(it);
            }
        }
        
        return -1;
    }
};
```

### Solution 2: Simplified BFS without Parity Optimization

```cpp
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int zeros = count(s.begin(), s.end(), '0');
        
        if(zeros == 0) return 0;
        
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(zeros);
        dist[zeros] = 0;
        
        while(!q.empty()) {
            int z = q.front();
            q.pop();
            
            // Try all possible ways to flip k indices
            // If we flip x zeros and (k-x) ones:
            // New zeros = z - x + (k - x) = z + k - 2x
            int minX = max(0, k - (n - z));  // At least this many zeros must be flipped
            int maxX = min(k, z);             // At most this many zeros can be flipped
            
            for(int x = minX; x <= maxX; x++) {
                int newZ = z + k - 2 * x;
                
                if(newZ >= 0 && newZ <= n && dist[newZ] == -1) {
                    dist[newZ] = dist[z] + 1;
                    
                    if(newZ == 0) {
                        return dist[newZ];
                    }
                    
                    q.push(newZ);
                }
            }
        }
        
        return -1;
    }
};
```

### Solution 3: With Early Termination

```cpp
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int zeros = 0;
        
        for(char c : s) {
            if(c == '0') zeros++;
        }
        
        if(zeros == 0) return 0;
        
        unordered_map<int, int> visited;
        queue<pair<int, int>> q; // {zeros, operations}
        q.push({zeros, 0});
        visited[zeros] = 0;
        
        while(!q.empty()) {
            auto [z, ops] = q.front();
            q.pop();
            
            // Calculate reachable states
            for(int flipZeros = max(0, k - (n - z)); flipZeros <= min(k, z); flipZeros++) {
                int flipOnes = k - flipZeros;
                int newZeros = z - flipZeros + flipOnes;
                
                if(newZeros == 0) {
                    return ops + 1;
                }
                
                if(newZeros >= 0 && newZeros <= n && visited.find(newZeros) == visited.end()) {
                    visited[newZeros] = ops + 1;
                    q.push({newZeros, ops + 1});
                }
            }
        }
        
        return -1;
    }
};
```

### Solution 4: Optimized with Unordered Set

```cpp
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int zeros = count(s.begin(), s.end(), '0');
        
        if(zeros == 0) return 0;
        if(k > n) return -1;
        
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({zeros, 0});
        visited.insert(zeros);
        
        while(!q.empty()) {
            int z = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            int minFlip = max(0, k - (n - z));
            int maxFlip = min(k, z);
            
            for(int flip = minFlip; flip <= maxFlip; flip++) {
                int newZ = z - flip + (k - flip);
                
                if(newZ == 0) return steps + 1;
                
                if(newZ >= 0 && newZ <= n && !visited.count(newZ)) {
                    visited.insert(newZ);
                    q.push({newZ, steps + 1});
                }
            }
        }
        
        return -1;
    }
};
```

---

## Key Takeaways

- **State-space search**: Problem can be modeled as graph traversal where nodes are states (zero counts)
- **BFS for shortest path**: Use BFS to find minimum operations (shortest path to target state)
- **State transition formula**: If current zeros = z, flip x zeros and (k-x) ones → new zeros = z + k - 2x
- **Reachability constraints**:
  - Must flip exactly k indices
  - Can flip at most z zeros (can't flip more than exist)
  - Must flip at least (k - number_of_ones) zeros if k > ones
- **Range calculation**:
  - Minimum new zeros: `z + k - 2*min(k, z)`
  - Maximum new zeros: `z + k - 2*max(0, k-n+z)`
- **Parity observation**: 
  - New zero count parity depends on k and current parity
  - Can separate states by parity for optimization
  - All states reachable in one operation have same parity
- **Optimization techniques**:
  - Use sets to track unvisited states by parity
  - Use `lower_bound` for range queries
  - Erase visited states to avoid redundant processing
  - Early termination when reaching 0 zeros
- **Impossibility detection**:
  - If BFS completes without reaching 0, return -1
  - Happens when state graph doesn't connect initial state to 0
- **Why track by zero count?**:
  - Zero count fully determines the state for optimization purposes
  - Don't need to track actual string configuration
  - Reduces state space from 2^n to n+1 states
- **Mathematical insight**:
  - Flipping k indices changes zero count by even number: k - 2x
  - Parity of zero count changes predictably
  - Can use modular arithmetic for analysis
- **Edge cases**:
  - Already all 1s (zeros = 0): return 0
  - k > n: might be impossible
  - k = 1: can flip any single index
  - All zeros, k = n: one operation makes all ones
- **Time complexity breakdown**:
  - BFS visits each state once: O(n)
  - Each state processes range of new states: O(n) in worst case
  - Set operations: O(log n)
  - Total: O(n² log n)
- **Space complexity**: O(n) for visited tracking and queue
- **Greedy doesn't work**: Can't simply flip zeros greedily due to constraints
- **Dynamic programming alternative**: Could model as DP but BFS is more natural
- **Graph perspective**: 
  - Nodes: zero counts (0 to n)
  - Edges: valid transitions (one operation)
  - Goal: shortest path from initial to 0
- **Comparison to similar problems**:
  - Related to state minimization problems
  - Binary string manipulation with constraints
  - Shortest path in implicit graph

