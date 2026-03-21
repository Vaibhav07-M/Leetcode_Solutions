# LeetCode Solutions

This repository contains my solutions to selected LeetCode problems.  
Each solution includes the final code along with a separate write-up explaining the reasoning, approach, and complexity.  
The goal is consistency, pattern recognition, and long-term reference — rather than just storing answers.

---

## Repository Layout

```
<problem-number>. <problem-title>/
    README.md       # Explanation, thought process, complexity, examples
    Solution.*      # Implementation (language may vary: cpp / py / java / etc.)
```

As more problems are added, directories and indexes will grow accordingly.

---

## Index Overview

This repository will be indexed in two parallel ways:
1. **by problem number range**
2. **by algorithmic category**

Both indexes start small and expand naturally.

---

## Category Index

| Category | Number of Problems | Link |
|----------|--------------------|------|
| Array | 49 | [View](#array) |
| BFS | 3 | [View](#bfs) |
| Backtracking | 3 | [View](#backtracking) |
| Binary Search | 8 | [View](#binary-search) |
| Binary Search Tree | 1 | [View](#binary-search-tree) |
| Binary Tree | 6 | [View](#binary-tree) |
| Bit Manipulation | 14 | [View](#bit-manipulation) |
| Combinatorics | 1 | [View](#combinatorics) |
| Coordinate Compression | 1 | [View](#coordinate-compression) |
| Counting | 2 | [View](#counting) |
| DFS | 6 | [View](#dfs) |
| Design | 1 | [View](#design) |
| Divide and Conquer | 3 | [View](#divide-and-conquer) |
| Dynamic Programming | 13 | [View](#dynamic-programming) |
| Enumeration | 2 | [View](#enumeration) |
| Geometry | 4 | [View](#geometry) |
| Graph | 5 | [View](#graph) |
| Greedy | 15 | [View](#greedy) |
| Hash Table | 9 | [View](#hash-table) |
| Heap (Priority Queue) | 5 | [View](#heap-priority-queue) |
| Line Sweep | 1 | [View](#line-sweep) |
| Math | 17 | [View](#math) |
| Matrix | 16 | [View](#matrix) |
| Monotonic Stack | 1 | [View](#monotonic-stack) |
| Ordered Set | 1 | [View](#ordered-set) |
| Prefix Sum | 8 | [View](#prefix-sum) |
| Recursion | 2 | [View](#recursion) |
| Rolling Hash | 1 | [View](#rolling-hash) |
| Segment Tree | 2 | [View](#segment-tree) |
| Shortest Path | 4 | [View](#shortest-path) |
| Simulation | 8 | [View](#simulation) |
| Sliding Window | 7 | [View](#sliding-window) |
| Sorting | 13 | [View](#sorting) |
| Stack | 2 | [View](#stack) |
| String | 21 | [View](#string) |
| Tree | 6 | [View](#tree) |
| Trie | 1 | [View](#trie) |
| Two Pointers | 3 | [View](#two-pointers) |
| Union Find | 2 | [View](#union-find) |

### Completed Problems

| # | Title | Difficulty | Category | Solution |
|---|--------|------------|----------|---------|
| 66 | Plus One | Easy | Array / Math | [View](./66.%20Plus%20One/) |
| 67 | Add Binary | Easy | Math / String / Bit Manipulation / Simulation | [View](./67.%20Add%20Binary/) |
| 85 | Maximal Rectangle | Hard | Array / Dynamic Programming / Stack / Matrix / Monotonic Stack | [View](./85.%20Maximal%20Rectangle/) |
| 110 | Balanced Binary Tree | Easy | Tree / DFS / Binary Tree | [View](./110.%20Balanced%20Binary%20Tree/) |
| 190 | Reverse Bits | Easy | Divide and Conquer / Bit Manipulation | [View](./190.%20Reverse%20Bits/) |
| 401 | Binary Watch | Easy | Backtracking / Bit Manipulation | [View](./401.%20Binary%20Watch/) |
| 693 | Binary Number with Alternating Bits | Easy | Bit Manipulation | [View](./693.%20Binary%20Number%20with%20Alternating%20Bits/) |
| 696 | Count Binary Substrings | Easy | String / Two Pointers | [View](./696.%20Count%20Binary%20Substrings/) |
| 712 | Minimum ASCII Delete Sum for Two Strings | Medium | String / Dynamic Programming | [View](./712.%20Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings/) |
| 744 | Find Smallest Letter Greater Than Target | Easy | Array / Binary Search | [View](./744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/) |
| 756 | Pyramid Transition Matrix | Medium | Hash Table / String / Backtracking | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 761 | Special Binary String | Hard | String / Recursion / Greedy | [View](./761.%20Special%20Binary%20String/) |
| 762 | Prime Number of Set Bits in Binary Representation | Easy | Math / Bit Manipulation | [View](./762.%20Prime%20Number%20of%20Set%20Bits%20in%20Binary%20Representation/) |
| 799 | Champagne Tower | Medium | Dynamic Programming / Simulation / Math | [View](./799.%20Champagne%20Tower/) |
| 840 | Magic Squares In Grid | Medium | Array / Hash Table / Math / Matrix | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 868 | Binary Gap | Easy | Bit Manipulation | [View](./868.%20Binary%20Gap/) |
| 865 | Smallest Subtree with all the Deepest Nodes | Medium | Tree / DFS / Binary Tree | [View](./865.%20Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/) |
| 961 | N-Repeated Element in Size 2N Array | Easy | Array / Hash Table | [View](./961.%20N-Repeated%20Element%20in%20Size%202N%20Array/) |
| 1009 | Complement of Base 10 Integer | Easy | Bit Manipulation | [View](./1009.%20Complement%20of%20Base%2010%20Integer/) |
| 1022 | Sum of Root To Leaf Binary Numbers | Easy | Tree / DFS / Binary Tree | [View](./1022.%20Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/) |
| 1161 | Maximum Level Sum of a Binary Tree | Medium | Tree / BFS / Binary Tree | [View](./1161.%20Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/) |
| 1200 | Minimum Absolute Difference | Easy | Array / Sorting | [View](./1200.%20Minimum%20Absolute%20Difference/) |
| 1266 | Minimum Time Visiting All Points | Easy | Array / Math / Geometry | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | Array / Binary Search / Matrix / Prefix Sum | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | Tree / DFS / Binary Tree / Dynamic Programming | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | Binary Search / Matrix | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1356 | Sort Integers by The Number of 1 Bits | Easy | Array / Bit Manipulation / Sorting / Counting | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 1382 | Balance a Binary Search Tree | Medium | Tree / DFS / Binary Search Tree / Binary Tree / Greedy / Divide and Conquer | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 1390 | Four Divisors | Medium | Array / Math | [View](./1390.%20Four%20Divisors/) |
| 1404 | Number of Steps to Reduce a Number in Binary Representation to One | Medium | String / Bit Manipulation | [View](./1404.%20Number%20of%20Steps%20to%20Reduce%20a%20Number%20in%20Binary%20Representation%20to%20One/) |
| 1411 | Number of Ways to Paint N × 3 Grid | Hard | Dynamic Programming / Math / Combinatorics | [View](./1411.%20Number%20of%20Ways%20to%20Paint%20N%20×%203%20Grid/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | String / Greedy / Math | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | String / Hash Table / Bit Manipulation / Rolling Hash | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |
| 1458 | Max Dot Product of Two Subsequences | Hard | Array / Dynamic Programming | [View](./1458.%20Max%20Dot%20Product%20of%20Two%20Subsequences/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | Array / Greedy / Sorting / Matrix | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1545 | Find Kth Bit in Nth Binary String | Medium | String / Recursion / Divide and Conquer | [View](./1545.%20Find%20Kth%20Bit%20in%20Nth%20Binary%20String/) |
| 1582 | Special Positions in a Binary Matrix | Easy | Array / Matrix | [View](./1582.%20Special%20Positions%20in%20a%20Binary%20Matrix/) |
| 1622 | Fancy Sequence | Hard | Design / Math / Segment Tree | [View](./1622.%20Fancy%20Sequence/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | String / Dynamic Programming / Stack | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |
| 1680 | Concatenation of Consecutive Binary Numbers | Medium | Math / Bit Manipulation / Simulation | [View](./1680.%20Concatenation%20of%20Consecutive%20Binary%20Numbers/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | String / Greedy / Math | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | Array / Matrix / Sorting | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1758 | Minimum Changes To Make Alternating Binary String | Easy | String / Greedy | [View](./1758.%20Minimum%20Changes%20To%20Make%20Alternating%20Binary%20String/) |
| 1784 | Check if Binary String Has at Most One Segment of Ones | Easy | String | [View](./1784.%20Check%20if%20Binary%20String%20Has%20at%20Most%20One%20Segment%20of%20Ones/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | Array / Greedy / Sorting / Two Pointers | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | Array / Matrix / Prefix Sum | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
| 1888 | Minimum Number of Flips to Make the Binary String Alternating | Medium | String / Sliding Window | [View](./1888.%20Minimum%20Number%20of%20Flips%20to%20Make%20the%20Binary%20String%20Alternating/) |
| 1895 | Largest Magic Square | Medium | Array / Matrix / Prefix Sum | [View](./1895.%20Largest%20Magic%20Square/) |
| 1970 | Last Day Where You Can Still Cross | Hard | Array / Binary Search / BFS / DFS / Union Find / Matrix | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 1975 | Maximum Matrix Sum | Medium | Array / Greedy / Matrix | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 1980 | Find Unique Binary String | Medium | Array / String / Backtracking | [View](./1980.%20Find%20Unique%20Binary%20String/) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | Easy | Array / Sorting / Sliding Window | [View](./1984.%20Minimum%20Difference%20Between%20Highest%20and%20Lowest%20of%20K%20Scores/) |
| 2402 | Meeting Rooms III | Hard | Heap / Sorting / Simulation | [View](./2402.%20Meeting%20Rooms%20III/) |
| 2483 | Minimum Penalty for a Shop | Medium | String / Prefix Sum | [View](./2483.%20Minimum%20Penalty%20for%20a%20Shop/) |
| 2943 | Maximize Area of Square Hole in Grid | Medium | Array / Sorting / Greedy | [View](./2943.%20Maximize%20Area%20of%20Square%20Hole%20in%20Grid/) |
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | Array / Hash Table / Enumeration / Math | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 2976 | Minimum Cost to Convert String I | Medium | Array / String / Graph / Shortest Path | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 2977 | Minimum Cost to Convert String II | Hard | String / Dynamic Programming / Graph / Shortest Path / Trie | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3010 | Divide an Array Into Subarrays With Minimum Cost I | Easy | Array / Greedy | [View](./3010.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20I/) |
| 3013 | Divide an Array Into Subarrays With Minimum Cost II | Hard | Array / Sliding Window / Heap (Priority Queue) / Ordered Set | [View](./3013.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20II/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | Array / Geometry / Math / Enumeration | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3070 | Count Submatrices with Top-Left Element and Sum Less Than k | Medium | Array / Matrix / Prefix Sum | [View](./3070.%20Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/) |
| 3075 | Maximize Happiness of Selected Children | Medium | Greedy / Sorting | [View](./3075.%20Maximize%20Happiness%20of%20Selected%20Children/) |
| 3129 | Find All Possible Stable Binary Arrays I | Medium | Array / Dynamic Programming | [View](./3129.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20I/) |
| 3130 | Find All Possible Stable Binary Arrays II | Hard | Array / Dynamic Programming | [View](./3130.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20II/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | Array / Matrix / Prefix Sum | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3296 | Minimum Number of Seconds to Make Mountain Height Zero | Medium | Binary Search / Math | [View](./3296.%20Minimum%20Number%20of%20Seconds%20to%20Make%20Mountain%20Height%20Zero/) |
| 3314 | Construct the Minimum Bitwise Array I | Easy | Array / Bit Manipulation | [View](./3314.%20Construct%20the%20Minimum%20Bitwise%20Array%20I/) |
| 3315 | Construct the Minimum Bitwise Array II | Medium | Array / Bit Manipulation | [View](./3315.%20Construct%20the%20Minimum%20Bitwise%20Array%20II/) |
| 3379 | Transformed Array | Easy | Array / Simulation | [View](./3379.%20Transformed%20Array/) |
| 3453 | Separate Squares I | Medium | Array / Binary Search / Geometry / Math / Sorting | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | Array / Binary Search / Geometry / Line Sweep / Coordinate Compression / Sorting | [View](./3454.%20Separate%20Squares%20II/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | Array / Greedy / Simulation | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | Array / Heap / Greedy / Simulation | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | Array / Matrix / Sliding Window / Sorting | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | Graph / Union Find / Binary Search / Greedy | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |
| 3634 | Minimum Removals to Balance Array | Medium | Array / Sorting / Sliding Window / Two Pointers | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |
| 3637 | Trionic Array I | Easy | Array | [View](./3637.%20Trionic%20Array%20I/) |
| 3640 | Trionic Array II | Hard | Array / Dynamic Programming | [View](./3640.%20Trionic%20Array%20II/) |
| 3643 | Flip Square Submatrix Vertically | Easy | Array / Matrix / Simulation | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | Graph / Shortest Path / Heap (Priority Queue) / Dynamic Programming | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | Array / Matrix / Graph / Shortest Path / Heap (Priority Queue) / Dynamic Programming | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | String / BFS / Math / Greedy | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |
| 3713 | Longest Balanced Substring I | Medium | String / Hash Table / Counting | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |
| 3714 | Longest Balanced Substring II | Medium | String / Hash Table / Prefix Sum | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |
| 3719 | Longest Balanced Subarray I | Medium | Array / Hash Table / Sliding Window | [View](./3719.%20Longest%20Balanced%20Subarray%20I/) |
| 3721 | Longest Balanced Subarray II | Hard | Array / Hash Table / Sliding Window / Segment Tree / Prefix Sum | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |

---

## By Category

### Array
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 66 | Plus One | Easy | [View](./66.%20Plus%20One/) |
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 744 | Find Smallest Letter Greater Than Target | Easy | [View](./744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 961 | N-Repeated Element in Size 2N Array | Easy | [View](./961.%20N-Repeated%20Element%20in%20Size%202N%20Array/) |
| 1200 | Minimum Absolute Difference | Easy | [View](./1200.%20Minimum%20Absolute%20Difference/) |
| 1266 | Minimum Time Visiting All Points | Easy | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1356 | Sort Integers by The Number of 1 Bits | Easy | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 1390 | Four Divisors | Medium | [View](./1390.%20Four%20Divisors/) |
| 1458 | Max Dot Product of Two Subsequences | Hard | [View](./1458.%20Max%20Dot%20Product%20of%20Two%20Subsequences/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1582 | Special Positions in a Binary Matrix | Easy | [View](./1582.%20Special%20Positions%20in%20a%20Binary%20Matrix/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
|
| 1895 | Largest Magic Square | Medium | [View](./1895.%20Largest%20Magic%20Square/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 1975 | Maximum Matrix Sum | Medium | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 1980 | Find Unique Binary String | Medium | [View](./1980.%20Find%20Unique%20Binary%20String/) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | Easy | [View](./1984.%20Minimum%20Difference%20Between%20Highest%20and%20Lowest%20of%20K%20Scores/) |
| 2402 | Meeting Rooms III | Hard | [View](./2402.%20Meeting%20Rooms%20III/) |
| 2943 | Maximize Area of Square Hole in Grid | Medium | [View](./2943.%20Maximize%20Area%20of%20Square%20Hole%20in%20Grid/) |
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 2976 | Minimum Cost to Convert String I | Medium | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 3010 | Divide an Array Into Subarrays With Minimum Cost I | Easy | [View](./3010.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20I/) |
| 3013 | Divide an Array Into Subarrays With Minimum Cost II | Hard | [View](./3013.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20II/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3070 | Count Submatrices with Top-Left Element and Sum Less Than k | Medium | [View](./3070.%20Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/) |
| 3075 | Maximize Happiness of Selected Children | Medium | [View](./3075.%20Maximize%20Happiness%20of%20Selected%20Children/) |
| 3129 | Find All Possible Stable Binary Arrays I | Medium | [View](./3129.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20I/) |
| 3130 | Find All Possible Stable Binary Arrays II | Hard | [View](./3130.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20II/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3314 | Construct the Minimum Bitwise Array I | Easy | [View](./3314.%20Construct%20the%20Minimum%20Bitwise%20Array%20I/) |
| 3315 | Construct the Minimum Bitwise Array II | Medium | [View](./3315.%20Construct%20the%20Minimum%20Bitwise%20Array%20II/) |
| 3379 | Transformed Array | Easy | [View](./3379.%20Transformed%20Array/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3634 | Minimum Removals to Balance Array | Medium | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |
| 3637 | Trionic Array I | Easy | [View](./3637.%20Trionic%20Array%20I/) |
| 3640 | Trionic Array II | Hard | [View](./3640.%20Trionic%20Array%20II/) |
| 3643 | Flip Square Submatrix Vertically | Easy | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |
| 3719 | Longest Balanced Subarray I | Medium | [View](./3719.%20Longest%20Balanced%20Subarray%20I/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |

### BFS
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1161 | Maximum Level Sum of a Binary Tree | Medium | [View](./1161.%20Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |

### Backtracking
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 401 | Binary Watch | Easy | [View](./401.%20Binary%20Watch/) |
| 756 | Pyramid Transition Matrix | Medium | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 1980 | Find Unique Binary String | Medium | [View](./1980.%20Find%20Unique%20Binary%20String/) |

### Binary Search
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 744 | Find Smallest Letter Greater Than Target | Easy | [View](./744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/) |
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 3296 | Minimum Number of Seconds to Make Mountain Height Zero | Medium | [View](./3296.%20Minimum%20Number%20of%20Seconds%20to%20Make%20Mountain%20Height%20Zero/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |

### Binary Search Tree
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |

### Binary Tree
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 110 | Balanced Binary Tree | Easy | [View](./110.%20Balanced%20Binary%20Tree/) |
| 1022 | Sum of Root To Leaf Binary Numbers | Easy | [View](./1022.%20Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/) |
| 865 | Smallest Subtree with all the Deepest Nodes | Medium | [View](./865.%20Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/) |
| 1161 | Maximum Level Sum of a Binary Tree | Medium | [View](./1161.%20Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |

### Bit Manipulation
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 67 | Add Binary | Easy | [View](./67.%20Add%20Binary/) |
| 190 | Reverse Bits | Easy | [View](./190.%20Reverse%20Bits/) |
| 401 | Binary Watch | Easy | [View](./401.%20Binary%20Watch/) |
| 693 | Binary Number with Alternating Bits | Easy | [View](./693.%20Binary%20Number%20with%20Alternating%20Bits/) |
| 756 | Pyramid Transition Matrix | Medium | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 762 | Prime Number of Set Bits in Binary Representation | Easy | [View](./762.%20Prime%20Number%20of%20Set%20Bits%20in%20Binary%20Representation/) |
| 868 | Binary Gap | Easy | [View](./868.%20Binary%20Gap/) |
| 1009 | Complement of Base 10 Integer | Easy | [View](./1009.%20Complement%20of%20Base%2010%20Integer/) |
| 1356 | Sort Integers by The Number of 1 Bits | Easy | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 1404 | Number of Steps to Reduce a Number in Binary Representation to One | Medium | [View](./1404.%20Number%20of%20Steps%20to%20Reduce%20a%20Number%20in%20Binary%20Representation%20to%20One/) |
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |
| 1680 | Concatenation of Consecutive Binary Numbers | Medium | [View](./1680.%20Concatenation%20of%20Consecutive%20Binary%20Numbers/) |
| 3314 | Construct the Minimum Bitwise Array I | Easy | [View](./3314.%20Construct%20the%20Minimum%20Bitwise%20Array%20I/) |
| 3315 | Construct the Minimum Bitwise Array II | Medium | [View](./3315.%20Construct%20the%20Minimum%20Bitwise%20Array%20II/) |

### Combinatorics
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1411 | Number of Ways to Paint N × 3 Grid | Hard | [View](./1411.%20Number%20of%20Ways%20to%20Paint%20N%20×%203%20Grid/) |

### Coordinate Compression
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |

### Counting
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1356 | Sort Integers by The Number of 1 Bits | Easy | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 3713 | Longest Balanced Substring I | Medium | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |

### DFS
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 110 | Balanced Binary Tree | Easy | [View](./110.%20Balanced%20Binary%20Tree/) |
| 1022 | Sum of Root To Leaf Binary Numbers | Easy | [View](./1022.%20Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/) |
| 865 | Smallest Subtree with all the Deepest Nodes | Medium | [View](./865.%20Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |

### Design
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1622 | Fancy Sequence | Hard | [View](./1622.%20Fancy%20Sequence/) |

### Divide and Conquer
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 190 | Reverse Bits | Easy | [View](./190.%20Reverse%20Bits/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 1545 | Find Kth Bit in Nth Binary String | Medium | [View](./1545.%20Find%20Kth%20Bit%20in%20Nth%20Binary%20String/) |

### Dynamic Programming
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 712 | Minimum ASCII Delete Sum for Two Strings | Medium | [View](./712.%20Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings/) |
| 799 | Champagne Tower | Medium | [View](./799.%20Champagne%20Tower/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1411 | Number of Ways to Paint N × 3 Grid | Hard | [View](./1411.%20Number%20of%20Ways%20to%20Paint%20N%20×%203%20Grid/) |
| 1458 | Max Dot Product of Two Subsequences | Hard | [View](./1458.%20Max%20Dot%20Product%20of%20Two%20Subsequences/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3129 | Find All Possible Stable Binary Arrays I | Medium | [View](./3129.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20I/) |
| 3130 | Find All Possible Stable Binary Arrays II | Hard | [View](./3130.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20II/) |
| 3640 | Trionic Array II | Hard | [View](./3640.%20Trionic%20Array%20II/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |

### Enumeration
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |

### Geometry
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1266 | Minimum Time Visiting All Points | Easy | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |

### Graph
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 2976 | Minimum Cost to Convert String I | Medium | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |

### Greedy
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 761 | Special Binary String | Hard | [View](./761.%20Special%20Binary%20String/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 1758 | Minimum Changes To Make Alternating Binary String | Easy | [View](./1758.%20Minimum%20Changes%20To%20Make%20Alternating%20Binary%20String/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1975 | Maximum Matrix Sum | Medium | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 2943 | Maximize Area of Square Hole in Grid | Medium | [View](./2943.%20Maximize%20Area%20of%20Square%20Hole%20in%20Grid/) |
| 3010 | Divide an Array Into Subarrays With Minimum Cost I | Easy | [View](./3010.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20I/) |
| 3075 | Maximize Happiness of Selected Children | Medium | [View](./3075.%20Maximize%20Happiness%20of%20Selected%20Children/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |

### Hash Table
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 756 | Pyramid Transition Matrix | Medium | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 961 | N-Repeated Element in Size 2N Array | Easy | [View](./961.%20N-Repeated%20Element%20in%20Size%202N%20Array/) |
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 3713 | Longest Balanced Substring I | Medium | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |
| 3714 | Longest Balanced Substring II | Medium | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |
| 3719 | Longest Balanced Subarray I | Medium | [View](./3719.%20Longest%20Balanced%20Subarray%20I/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |

### Heap (Priority Queue)
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 2402 | Meeting Rooms III | Hard | [View](./2402.%20Meeting%20Rooms%20III/) |
| 3013 | Divide an Array Into Subarrays With Minimum Cost II | Hard | [View](./3013.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20II/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |

### Line Sweep
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |

### Math
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 66 | Plus One | Easy | [View](./66.%20Plus%20One/) |
| 67 | Add Binary | Easy | [View](./67.%20Add%20Binary/) |
| 762 | Prime Number of Set Bits in Binary Representation | Easy | [View](./762.%20Prime%20Number%20of%20Set%20Bits%20in%20Binary%20Representation/) |
| 799 | Champagne Tower | Medium | [View](./799.%20Champagne%20Tower/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 1266 | Minimum Time Visiting All Points | Easy | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 1390 | Four Divisors | Medium | [View](./1390.%20Four%20Divisors/) |
| 1411 | Number of Ways to Paint N × 3 Grid | Hard | [View](./1411.%20Number%20of%20Ways%20to%20Paint%20N%20×%203%20Grid/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1622 | Fancy Sequence | Hard | [View](./1622.%20Fancy%20Sequence/) |
| 1680 | Concatenation of Consecutive Binary Numbers | Medium | [View](./1680.%20Concatenation%20of%20Consecutive%20Binary%20Numbers/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3296 | Minimum Number of Seconds to Make Mountain Height Zero | Medium | [View](./3296.%20Minimum%20Number%20of%20Seconds%20to%20Make%20Mountain%20Height%20Zero/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |

### Matrix
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1582 | Special Positions in a Binary Matrix | Easy | [View](./1582.%20Special%20Positions%20in%20a%20Binary%20Matrix/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
| 1895 | Largest Magic Square | Medium | [View](./1895.%20Largest%20Magic%20Square/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 1975 | Maximum Matrix Sum | Medium | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 3070 | Count Submatrices with Top-Left Element and Sum Less Than k | Medium | [View](./3070.%20Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3643 | Flip Square Submatrix Vertically | Easy | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |

### Monotonic Stack
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |

### Ordered Set
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3013 | Divide an Array Into Subarrays With Minimum Cost II | Hard | [View](./3013.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20II/) |

### Prefix Sum
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
| 1895 | Largest Magic Square | Medium | [View](./1895.%20Largest%20Magic%20Square/) |
| 2483 | Minimum Penalty for a Shop | Medium | [View](./2483.%20Minimum%20Penalty%20for%20a%20Shop/) |
| 3070 | Count Submatrices with Top-Left Element and Sum Less Than k | Medium | [View](./3070.%20Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3714 | Longest Balanced Substring II | Medium | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |

### Recursion
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 761 | Special Binary String | Hard | [View](./761.%20Special%20Binary%20String/) |
| 1545 | Find Kth Bit in Nth Binary String | Medium | [View](./1545.%20Find%20Kth%20Bit%20in%20Nth%20Binary%20String/) |

### Rolling Hash
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |

### Segment Tree
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1622 | Fancy Sequence | Hard | [View](./1622.%20Fancy%20Sequence/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |

### Shortest Path
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 2976 | Minimum Cost to Convert String I | Medium | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |

### Simulation
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 67 | Add Binary | Easy | [View](./67.%20Add%20Binary/) |
| 799 | Champagne Tower | Medium | [View](./799.%20Champagne%20Tower/) |
| 1680 | Concatenation of Consecutive Binary Numbers | Medium | [View](./1680.%20Concatenation%20of%20Consecutive%20Binary%20Numbers/) |
| 2402 | Meeting Rooms III | Hard | [View](./2402.%20Meeting%20Rooms%20III/) |
| 3379 | Transformed Array | Easy | [View](./3379.%20Transformed%20Array/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3643 | Flip Square Submatrix Vertically | Easy | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |

### Sliding Window
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1888 | Minimum Number of Flips to Make the Binary String Alternating | Medium | [View](./1888.%20Minimum%20Number%20of%20Flips%20to%20Make%20the%20Binary%20String%20Alternating/) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | Easy | [View](./1984.%20Minimum%20Difference%20Between%20Highest%20and%20Lowest%20of%20K%20Scores/) |
| 3013 | Divide an Array Into Subarrays With Minimum Cost II | Hard | [View](./3013.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20II/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3634 | Minimum Removals to Balance Array | Medium | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |
| 3719 | Longest Balanced Subarray I | Medium | [View](./3719.%20Longest%20Balanced%20Subarray%20I/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |

### Sorting
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1200 | Minimum Absolute Difference | Easy | [View](./1200.%20Minimum%20Absolute%20Difference/) |
| 1356 | Sort Integers by The Number of 1 Bits | Easy | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | Easy | [View](./1984.%20Minimum%20Difference%20Between%20Highest%20and%20Lowest%20of%20K%20Scores/) |
| 2402 | Meeting Rooms III | Hard | [View](./2402.%20Meeting%20Rooms%20III/) |
| 2943 | Maximize Area of Square Hole in Grid | Medium | [View](./2943.%20Maximize%20Area%20of%20Square%20Hole%20in%20Grid/) |
| 3075 | Maximize Happiness of Selected Children | Medium | [View](./3075.%20Maximize%20Happiness%20of%20Selected%20Children/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3634 | Minimum Removals to Balance Array | Medium | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |

### Stack
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |

### String
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 67 | Add Binary | Easy | [View](./67.%20Add%20Binary/) |
| 696 | Count Binary Substrings | Easy | [View](./696.%20Count%20Binary%20Substrings/) |
| 712 | Minimum ASCII Delete Sum for Two Strings | Medium | [View](./712.%20Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings/) |
| 756 | Pyramid Transition Matrix | Medium | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 761 | Special Binary String | Hard | [View](./761.%20Special%20Binary%20String/) |
| 1404 | Number of Steps to Reduce a Number in Binary Representation to One | Medium | [View](./1404.%20Number%20of%20Steps%20to%20Reduce%20a%20Number%20in%20Binary%20Representation%20to%20One/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |
| 1545 | Find Kth Bit in Nth Binary String | Medium | [View](./1545.%20Find%20Kth%20Bit%20in%20Nth%20Binary%20String/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 1758 | Minimum Changes To Make Alternating Binary String | Easy | [View](./1758.%20Minimum%20Changes%20To%20Make%20Alternating%20Binary%20String/) |
| 1784 | Check if Binary String Has at Most One Segment of Ones | Easy | [View](./1784.%20Check%20if%20Binary%20String%20Has%20at%20Most%20One%20Segment%20of%20Ones/) |
| 1888 | Minimum Number of Flips to Make the Binary String Alternating | Medium | [View](./1888.%20Minimum%20Number%20of%20Flips%20to%20Make%20the%20Binary%20String%20Alternating/) |
| 1980 | Find Unique Binary String | Medium | [View](./1980.%20Find%20Unique%20Binary%20String/) |
| 2483 | Minimum Penalty for a Shop | Medium | [View](./2483.%20Minimum%20Penalty%20for%20a%20Shop/) |
| 2976 | Minimum Cost to Convert String I | Medium | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |
| 3713 | Longest Balanced Substring I | Medium | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |
| 3714 | Longest Balanced Substring II | Medium | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |

### Tree
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 110 | Balanced Binary Tree | Easy | [View](./110.%20Balanced%20Binary%20Tree/) |
| 1022 | Sum of Root To Leaf Binary Numbers | Easy | [View](./1022.%20Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/) |
| 865 | Smallest Subtree with all the Deepest Nodes | Medium | [View](./865.%20Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/) |
| 1161 | Maximum Level Sum of a Binary Tree | Medium | [View](./1161.%20Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |

### Trie
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |

### Two Pointers
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 696 | Count Binary Substrings | Easy | [View](./696.%20Count%20Binary%20Substrings/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 3634 | Minimum Removals to Balance Array | Medium | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |

### Union Find
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |

---

## Documentation Standards

Each `README.md` inside a problem folder contains:
- problem summary (paraphrased)
- intuition behind the approach
- detailed algorithm steps
- complexity analysis
- examples if needed
- edge-case notes
- code implementation

---

## Why This Repo Exists

- personal reference archive  
- learn patterns instead of isolated answers  
- ensure explanations prove real understanding  
- maintain quality instead of quantity  
- switch languages without breaking structure

---

## Notes

- only problems I choose to solve are included  
- multiple language versions may be added later  
- indexes will expand as more problems are completed

---

End of README.

