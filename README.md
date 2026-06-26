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
| Array | 102 | [View](#array) |
| Backtracking | 3 | [View](#backtracking) |
| BFS | 10 | [View](#bfs) |
| Binary Search | 16 | [View](#binary-search) |
| Binary Search Tree | 1 | [View](#binary-search-tree) |
| Binary Tree | 7 | [View](#binary-tree) |
| Bit Manipulation | 13 | [View](#bit-manipulation) |
| Combinatorics | 1 | [View](#combinatorics) |
| Coordinate Compression | 2 | [View](#coordinate-compression) |
| Counting | 10 | [View](#counting) |
| DFS | 10 | [View](#dfs) |
| Design | 2 | [View](#design) |
| Divide and Conquer | 3 | [View](#divide-and-conquer) |
| Dynamic Programming | 29 | [View](#dynamic-programming) |
| Enumeration | 3 | [View](#enumeration) |
| Geometry | 6 | [View](#geometry) |
| Graph | 9 | [View](#graph) |
| Greedy | 25 | [View](#greedy) |
| Hash Table | 21 | [View](#hash-table) |
| Heap (Priority Queue) | 5 | [View](#heap-priority-queue) |
| Line Sweep | 1 | [View](#line-sweep) |
| Linked List | 3 | [View](#linked-list) |
| Math | 38 | [View](#math) |
| Matrix | 33 | [View](#matrix) |
| Matrix Exponentiation | 1 | [View](#matrix-exponentiation) |
| Monotonic Stack | 2 | [View](#monotonic-stack) |
| Ordered Set | 2 | [View](#ordered-set) |
| Prefix Sum | 20 | [View](#prefix-sum) |
| Recursion | 2 | [View](#recursion) |
| Rolling Hash | 1 | [View](#rolling-hash) |
| Segment Tree | 2 | [View](#segment-tree) |
| Shortest Path | 4 | [View](#shortest-path) |
| Simulation | 24 | [View](#simulation) |
| Sliding Window | 8 | [View](#sliding-window) |
| Sorting | 24 | [View](#sorting) |
| Square Root Decomposition | 1 | [View](#square-root-decomposition) |
| Stack | 3 | [View](#stack) |
| String | 40 | [View](#string) |
| Suffix | 1 | [View](#suffix) |
| Trie | 3 | [View](#trie) |
| Tree | 9 | [View](#tree) |
| Two Pointers | 8 | [View](#two-pointers) |
| Union Find | 3 | [View](#union-find) |

### Completed Problems

| # | Title | Difficulty | Category | Solution |
|---|--------|------------|----------|---------|
| 33 | Search in Rotated Sorted Array | Medium | Array / Binary Search | [View](./33.%20Search%20in%20Rotated%20Sorted%20Array/) |
| 48 | Rotate Image | Medium | Array / Math / Matrix | [View](./48.%20Rotate%20Image/) |
| 61 | Rotate List | Medium | Linked List / Two Pointers | [View](./61.%20Rotate%20List/) |
| 66 | Plus One | Easy | Array / Math | [View](./66.%20Plus%20One/) |
| 67 | Add Binary | Easy | Math / String / Bit Manipulation / Simulation | [View](./67.%20Add%20Binary/) |
| 85 | Maximal Rectangle | Hard | Array / Dynamic Programming / Stack / Matrix / Monotonic Stack | [View](./85.%20Maximal%20Rectangle/) |
| 110 | Balanced Binary Tree | Easy | Tree / DFS / Binary Tree | [View](./110.%20Balanced%20Binary%20Tree/) |
| 153 | Find Minimum in Rotated Sorted Array | Medium | Array / Binary Search | [View](./153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/) |
| 154 | Find Minimum in Rotated Sorted Array II | Hard | Array / Binary Search | [View](./154.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array%20II/) |
| 190 | Reverse Bits | Easy | Divide and Conquer / Bit Manipulation | [View](./190.%20Reverse%20Bits/) |
| 396 | Rotate Function | Medium | Array / Math / Dynamic Programming | [View](./396.%20Rotate%20Function/) |
| 401 | Binary Watch | Easy | Backtracking / Bit Manipulation | [View](./401.%20Binary%20Watch/) |
| 657 | Robot Return to Origin | Easy | String / Simulation | [View](./657.%20Robot%20Return%20to%20Origin/) |
| 693 | Binary Number with Alternating Bits | Easy | Bit Manipulation | [View](./693.%20Binary%20Number%20with%20Alternating%20Bits/) |
| 696 | Count Binary Substrings | Easy | String / Two Pointers | [View](./696.%20Count%20Binary%20Substrings/) |
| 712 | Minimum ASCII Delete Sum for Two Strings | Medium | String / Dynamic Programming | [View](./712.%20Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings/) |
| 744 | Find Smallest Letter Greater Than Target | Easy | Array / Binary Search | [View](./744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/) |
| 756 | Pyramid Transition Matrix | Medium | Hash Table / String / Backtracking | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 761 | Special Binary String | Hard | String / Recursion / Greedy | [View](./761.%20Special%20Binary%20String/) |
| 762 | Prime Number of Set Bits in Binary Representation | Easy | Math / Bit Manipulation | [View](./762.%20Prime%20Number%20of%20Set%20Bits%20in%20Binary%20Representation/) |
| 788 | Rotated Digits | Medium | Math / Dynamic Programming | [View](./788.%20Rotated%20Digits/) |
| 796 | Rotate String | Easy | String / Simulation | [View](./796.%20Rotate%20String/) |
| 799 | Champagne Tower | Medium | Dynamic Programming / Simulation / Math | [View](./799.%20Champagne%20Tower/) |
| 840 | Magic Squares In Grid | Medium | Array / Hash Table / Math / Matrix | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 868 | Binary Gap | Easy | Bit Manipulation | [View](./868.%20Binary%20Gap/) |
| 865 | Smallest Subtree with all the Deepest Nodes | Medium | Tree / DFS / Binary Tree | [View](./865.%20Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/) |
| 874 | Walking Robot Simulation | Medium | Simulation | [View](./874.%20Walking%20Robot%20Simulation/) |
| 961 | N-Repeated Element in Size 2N Array | Easy | Array / Hash Table | [View](./961.%20N-Repeated%20Element%20in%20Size%202N%20Array/) |
| 1009 | Complement of Base 10 Integer | Easy | Bit Manipulation | [View](./1009.%20Complement%20of%20Base%2010%20Integer/) |
| 3161 | Block Placement Queries | Hard | Ordered Set / Array / Binary Search | [View](./3161.%20Block%20Placement%20Queries/) |
| 1022 | Sum of Root To Leaf Binary Numbers | Easy | Tree / DFS / Binary Tree | [View](./1022.%20Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/) |
| 1161 | Maximum Level Sum of a Binary Tree | Medium | Tree / BFS / Binary Tree | [View](./1161.%20Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/) |
| 1189 | Maximum Number of Balloons | Easy | String / Hash Table / Counting | [View](./1189.%20Maximum%20Number%20of%20Balloons/) |
| 1200 | Minimum Absolute Difference | Easy | Array / Sorting | [View](./1200.%20Minimum%20Absolute%20Difference/) |
| 1266 | Minimum Time Visiting All Points | Easy | Array / Math / Geometry | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | Array / Binary Search / Matrix / Prefix Sum | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1306 | Jump Game III | Medium | Array / BFS / DFS | [View](./1306.%20Jump%20Game%20III/) |
| 1320 | Minimum Distance to Type a Word Using Two Fingers | Hard | String / Dynamic Programming | [View](./1320.%20Minimum%20Distance%20to%20Type%20a%20Word%20Using%20Two%20Fingers/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | Tree / DFS / Binary Tree / Dynamic Programming | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1340 | Jump Game V | Hard | Array / Dynamic Programming / DFS | [View](./1340.%20Jump%20Game%20V/) |
| 1344 | Angle Between Hands of a Clock | Medium | Math / Geometry | [View](./1344.%20Angle%20Between%20Hands%20of%20a%20Clock/) |
| 1345 | Jump Game IV | Hard | Array / BFS / Graph / Hash Table | [View](./1345.%20Jump%20Game%20IV/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | Binary Search / Matrix | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1356 | Sort Integers by The Number of 1 Bits | Easy | Array / Bit Manipulation / Sorting / Counting | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 1382 | Balance a Binary Search Tree | Medium | Tree / DFS / Binary Search Tree / Binary Tree / Greedy / Divide and Conquer | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 1390 | Four Divisors | Medium | Array / Math | [View](./1390.%20Four%20Divisors/) |
| 1391 | Check if There is a Valid Path in a Grid | Medium | Graph / BFS / DFS / Matrix | [View](./1391.%20Check%20if%20There%20is%20a%20Valid%20Path%20in%20a%20Grid/) |
| 1404 | Number of Steps to Reduce a Number in Binary Representation to One | Medium | String / Bit Manipulation | [View](./1404.%20Number%20of%20Steps%20to%20Reduce%20a%20Number%20in%20Binary%20Representation%20to%20One/) |
| 1411 | Number of Ways to Paint N × 3 Grid | Hard | Dynamic Programming / Math / Combinatorics | [View](./1411.%20Number%20of%20Ways%20to%20Paint%20N%20×%203%20Grid/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | String / Greedy / Math | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | String / Hash Table / Bit Manipulation / Rolling Hash | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |
| 1458 | Max Dot Product of Two Subsequences | Hard | Array / Dynamic Programming | [View](./1458.%20Max%20Dot%20Product%20of%20Two%20Subsequences/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | Array / Greedy / Sorting / Matrix | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1545 | Find Kth Bit in Nth Binary String | Medium | String / Recursion / Divide and Conquer | [View](./1545.%20Find%20Kth%20Bit%20in%20Nth%20Binary%20String/) |
| 1559 | Detect Cycles in 2D Grid | Medium | DFS / Matrix | [View](./1559.%20Detect%20Cycles%20in%202D%20Grid/) |
| 1582 | Special Positions in a Binary Matrix | Easy | Array / Matrix | [View](./1582.%20Special%20Positions%20in%20a%20Binary%20Matrix/) |
| 1594 | Maximum Non Negative Product in a Matrix | Medium | Array / Dynamic Programming / Matrix | [View](./1594.%20Maximum%20Non%20Negative%20Product%20in%20a%20Matrix/) |
| 1622 | Fancy Sequence | Hard | Design / Math / Segment Tree | [View](./1622.%20Fancy%20Sequence/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | String / Dynamic Programming / Stack | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |
| 1665 | Minimum Initial Energy to Finish Tasks | Hard | Array / Greedy / Sorting | [View](./1665.%20Minimum%20Initial%20Energy%20to%20Finish%20Tasks/) |
| 1674 | Minimum Moves to Make Array Complementary | Medium | Array / Greedy / Prefix Sum | [View](./1674.%20Minimum%20Moves%20to%20Make%20Array%20Complementary/) |
| 1680 | Concatenation of Consecutive Binary Numbers | Medium | Math / Bit Manipulation / Simulation | [View](./1680.%20Concatenation%20of%20Consecutive%20Binary%20Numbers/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | String / Greedy / Math | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 1722 | Minimize Hamming Distance After Swap Operations | Medium | Array / Union Find | [View](./1722.%20Minimize%20Hamming%20Distance%20After%20Swap%20Operations/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | Array / Matrix / Sorting | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1732 | Find the Highest Altitude | Easy | Array / Prefix Sum | [View](./1732.%20Find%20the%20Highest%20Altitude/) |
| 1752 | Check if Array Is Sorted and Rotated | Easy | Array | [View](./1752.%20Check%20if%20Array%20Is%20Sorted%20and%20Rotated/) |
| 1758 | Minimum Changes To Make Alternating Binary String | Easy | String / Greedy | [View](./1758.%20Minimum%20Changes%20To%20Make%20Alternating%20Binary%20String/) |
| 1784 | Check if Binary String Has at Most One Segment of Ones | Easy | String | [View](./1784.%20Check%20if%20Binary%20String%20Has%20at%20Most%20One%20Segment%20of%20Ones/) |
| 1833 | Maximum Ice Cream Bars | Medium | Array / Greedy / Counting / Sorting | [View](./1833.%20Maximum%20Ice%20Cream%20Bars/) |
| 1840 | Maximum Building Height | Hard | Greedy / Math / Sorting | [View](./1840.%20Maximum%20Building%20Height/) |
| 1848 | Minimum Distance to the Target Element | Easy | Array | [View](./1848.%20Minimum%20Distance%20to%20the%20Target%20Element/) |
| 1855 | Maximum Distance Between a Pair of Values | Medium | Array / Two Pointers | [View](./1855.%20Maximum%20Distance%20Between%20a%20Pair%20of%20Values/) |
| 1861 | Rotating the Box | Medium | Matrix / Simulation | [View](./1861.%20Rotating%20the%20Box/) |
| 1871 | Jump Game VII | Medium | String / BFS / Prefix Sum / Sliding Window | [View](./1871.%20Jump%20Game%20VII/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | Array / Greedy / Sorting / Two Pointers | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | Array / Matrix / Prefix Sum | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
| 1886 | Determine Whether Matrix Can Be Obtained By Rotation | Easy | Matrix / Simulation | [View](./1886.%20Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/) |
| 1888 | Minimum Number of Flips to Make the Binary String Alternating | Medium | String / Sliding Window | [View](./1888.%20Minimum%20Number%20of%20Flips%20to%20Make%20the%20Binary%20String%20Alternating/) |
| 1895 | Largest Magic Square | Medium | Array / Matrix / Prefix Sum | [View](./1895.%20Largest%20Magic%20Square/) |
| 1914 | Cyclically Rotating a Grid | Medium | Matrix / Simulation | [View](./1914.%20Cyclically%20Rotating%20a%20Grid/) |
| 1970 | Last Day Where You Can Still Cross | Hard | Array / Binary Search / BFS / DFS / Union Find / Matrix | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 1975 | Maximum Matrix Sum | Medium | Array / Greedy / Matrix | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 1980 | Find Unique Binary String | Medium | Array / String / Backtracking | [View](./1980.%20Find%20Unique%20Binary%20String/) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | Easy | Array / Sorting / Sliding Window | [View](./1984.%20Minimum%20Difference%20Between%20Highest%20and%20Lowest%20of%20K%20Scores/) |
| 2033 | Minimum Operations to Make a Uni-Value Grid | Medium | Array / Matrix / Math / Sorting | [View](./2033.%20Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/) |
| 2069 | Walking Robot Simulation II | Medium | Design / Simulation / Math | [View](./2069.%20Walking%20Robot%20Simulation%20II/) |
| 2075 | Decode the Slanted Ciphertext | Medium | String / Matrix / Simulation | [View](./2075.%20Decode%20the%20Slanted%20Ciphertext/) |
| 2078 | Two Furthest Houses With Different Colors | Easy | Array | [View](./2078.%20Two%20Furthest%20Houses%20With%20Different%20Colors/) |
| 2095 | Delete the Middle Node of a Linked List | Medium | Linked List / Two Pointers | [View](./2095.%20Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/) |
| 2126 | Destroying Asteroids | Medium | Greedy / Sorting | [View](./2126.%20Destroying%20Asteroids/) |
| 2130 | Maximum Twin Sum of a Linked List | Medium | Linked List / Two Pointers | [View](./2130.%20Maximum%20Twin%20Sum%20of%20a%20Linked%20List/) |
| 2144 | Minimum Cost of Buying Candies With Discount | Easy | Greedy / Sorting | [View](./2144.%20Minimum%20Cost%20of%20Buying%20Candies%20With%20Discount/) |
| 2161 | Partition Array According to Given Pivot | Easy | Array | [View](./2161.%20Partition%20Array%20According%20to%20Given%20Pivot/) |
| 2196 | Create Binary Tree From Descriptions | Medium | Tree / Hash Table | [View](./2196.%20Create%20Binary%20Tree%20From%20Descriptions/) |
| 2402 | Meeting Rooms III | Hard | Heap / Sorting / Simulation | [View](./2402.%20Meeting%20Rooms%20III/) |
| 2463 | Minimum Total Distance Traveled | Hard | Array / Dynamic Programming / Sorting | [View](./2463.%20Minimum%20Total%20Distance%20Traveled/) |
| 2483 | Minimum Penalty for a Shop | Medium | String / Prefix Sum | [View](./2483.%20Minimum%20Penalty%20for%20a%20Shop/) |
| 2515 | Shortest Distance to Target String in a Circular Array | Easy | Array / String | [View](./2515.%20Shortest%20Distance%20to%20Target%20String%20in%20a%20Circular%20Array/) |
| 2540 | Minimum Common Value | Easy | Array / Two Pointers | [View](./2540.%20Minimum%20Common%20Value/) |
| 2553 | Separate the Digits in an Array | Easy | Array / Math | [View](./2553.%20Separate%20the%20Digits%20in%20an%20Array/) |
| 2573 | Find the String with LCP | Hard | String / Dynamic Programming / Matrix | [View](./2573.%20Find%20the%20String%20with%20LCP/) |
| 2574 | Left and Right Sum Differences | Easy | Array / Prefix Sum | [View](./2574.%20Left%20and%20Right%20Sum%20Differences/) |
| 2615 | Sum of Distances | Medium | Array / Hash Table / Prefix Sum | [View](./2615.%20Sum%20of%20Distances/) |
| 2657 | Find the Prefix Common Array of Two Arrays | Medium | Array | [View](./2657.%20Find%20the%20Prefix%20Common%20Array%20of%20Two%20Arrays/) |
| 2751 | Robot Collisions | Hard | Array / Stack / Sorting / Simulation | [View](./2751.%20Robot%20Collisions/) |
| 2770 | Maximum Number of Jumps to Reach the Last Index | Medium | Dynamic Programming / Segment Tree | [View](./2770.%20Maximum%20Number%20of%20Jumps%20to%20Reach%20the%20Last%20Index/) |
| 2784 | Check if Array is Good | Easy | Array / Hash Table / Counting | [View](./2784.%20Check%20if%20Array%20is%20Good/) |
| 2833 | Furthest Point From Origin | Easy | String / Math | [View](./2833.%20Furthest%20Point%20From%20Origin/) |
| 2839 | Check if Strings Can be Made Equal With Operations I | Easy | String / Simulation | [View](./2839.%20Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20I/) |
| 2840 | Check if Strings Can be Made Equal With Operations II | Medium | String / Hash Table / Counting | [View](./2840.%20Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20II/) |
| 2906 | Construct Product Matrix | Medium | Array / Matrix / Math / Prefix Sum | [View](./2906.%20Construct%20Product%20Matrix/) |
| 2943 | Maximize Area of Square Hole in Grid | Medium | Array / Sorting / Greedy | [View](./2943.%20Maximize%20Area%20of%20Square%20Hole%20in%20Grid/) |
| 2946 | Matrix Similarity After Cyclic Shifts | Easy | Matrix / Simulation | [View](./2946.%20Matrix%20Similarity%20After%20Cyclic%20Shifts/) |
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | Array / Hash Table / Enumeration / Math | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 2976 | Minimum Cost to Convert String I | Medium | Array / String / Graph / Shortest Path | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 2977 | Minimum Cost to Convert String II | Hard | String / Dynamic Programming / Graph / Shortest Path / Trie | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3010 | Divide an Array Into Subarrays With Minimum Cost I | Easy | Array / Greedy | [View](./3010.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20I/) |
| 3013 | Divide an Array Into Subarrays With Minimum Cost II | Hard | Array / Sliding Window / Heap (Priority Queue) / Ordered Set | [View](./3013.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20II/) |
| 3043 | Find the Length of the Longest Common Prefix | Medium | Trie | [View](./3043.%20Find%20the%20Length%20of%20the%20Longest%20Common%20Prefix/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | Array / Geometry / Math / Enumeration | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3070 | Count Submatrices with Top-Left Element and Sum Less Than k | Medium | Array / Matrix / Prefix Sum | [View](./3070.%20Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/) |
| 3075 | Maximize Happiness of Selected Children | Medium | Greedy / Sorting | [View](./3075.%20Maximize%20Happiness%20of%20Selected%20Children/) |
| 3093 | Longest Common Suffix Queries | Hard | Trie / String | [View](./3093.%20Longest%20Common%20Suffix%20Queries/) |
| 3120 | Count the Number of Special Characters I | Easy | String / Hash Table | [View](./3120.%20Count%20the%20Number%20of%20Special%20Characters%20I/) |
| 3121 | Count the Number of Special Characters II | Medium | String / Counting | [View](./3121.%20Count%20the%20Number%20of%20Special%20Characters%20II/) |
| 3129 | Find All Possible Stable Binary Arrays I | Medium | Array / Dynamic Programming | [View](./3129.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20I/) |
| 3130 | Find All Possible Stable Binary Arrays II | Hard | Array / Dynamic Programming | [View](./3130.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20II/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | Array / Matrix / Prefix Sum | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3225 | Maximum Score From Grid Operations | Hard | Array / Dynamic Programming / Matrix / Prefix Sum | [View](./3225.%20Maximum%20Score%20From%20Grid%20Operations/) |
| 3296 | Minimum Number of Seconds to Make Mountain Height Zero | Medium | Binary Search / Math | [View](./3296.%20Minimum%20Number%20of%20Seconds%20to%20Make%20Mountain%20Height%20Zero/) |
| 3300 | Minimum Element After Replacement With Digit Sum | Easy | Array / Math | [View](./3300.%20Minimum%20Element%20After%20Replacement%20With%20Digit%20Sum/) |
| 3314 | Construct the Minimum Bitwise Array I | Easy | Array / Bit Manipulation | [View](./3314.%20Construct%20the%20Minimum%20Bitwise%20Array%20I/) |
| 3315 | Construct the Minimum Bitwise Array II | Medium | Array / Bit Manipulation | [View](./3315.%20Construct%20the%20Minimum%20Bitwise%20Array%20II/) |
| 3379 | Transformed Array | Easy | Array / Simulation | [View](./3379.%20Transformed%20Array/) |
| 3418 | Maximum Amount of Money Robot Can Earn | Medium | Array / Dynamic Programming / Matrix | [View](./3418.%20Maximum%20Amount%20of%20Money%20Robot%20Can%20Earn/) |
| 3453 | Separate Squares I | Medium | Array / Binary Search / Geometry / Math / Sorting | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | Array / Binary Search / Geometry / Line Sweep / Coordinate Compression / Sorting | [View](./3454.%20Separate%20Squares%20II/) |
| 3464 | Maximize the Distance Between Points on a Square | Hard | Array / Binary Search / Geometry / Sorting | [View](./3464.%20Maximize%20the%20Distance%20Between%20Points%20on%20a%20Square/) |
| 3474 | Lexicographically Smallest Generated String | Hard | String / Greedy | [View](./3474.%20Lexicographically%20Smallest%20Generated%20String/) |
| 3488 | Closest Equal Element Queries | Medium | Array / Hash Table / Binary Search | [View](./3488.%20Closest%20Equal%20Element%20Queries/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | Array / Greedy / Simulation | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | Array / Heap / Greedy / Simulation | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3546 | Equal Sum Grid Partition I | Medium | Array / Matrix / Prefix Sum | [View](./3546.%20Equal%20Sum%20Grid%20Partition%20I/) |
| 3548 | Equal Sum Grid Partition II | Hard | Array / Hash Table / Matrix / Prefix Sum | [View](./3548.%20Equal%20Sum%20Grid%20Partition%20II/) |
| 3558 | Number of Ways to Assign Edge Weights I | Medium | Tree / BFS / Math | [View](./3558.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20I/) |
| 3559 | Number of Ways to Assign Edge Weights II | Hard | Tree / Lowest Common Ancestor / Math | [View](./3559.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20II/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | Array / Matrix / Sliding Window / Sorting | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | Graph / Union Find / Binary Search / Greedy | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |
| 3612 | Process String with Special Operations I | Medium | String / Stack / Simulation | [View](./3612.%20Process%20String%20with%20Special%20Operations%20I/) |
| 3614 | Process String with Special Operations II | Hard | String / Stack / Simulation | [View](./3614.%20Process%20String%20with%20Special%20Operations%20II/) |
| 3633 | Earliest Finish Time for Land and Water Rides I | Easy | Greedy / Simulation | [View](./3633.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20I/) |
| 3634 | Minimum Removals to Balance Array | Medium | Array / Sorting / Sliding Window / Two Pointers | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |
| 3635 | Earliest Finish Time for Land and Water Rides II | Medium | Greedy / Simulation | [View](./3635.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20II/) |
| 3637 | Trionic Array I | Easy | Array | [View](./3637.%20Trionic%20Array%20I/) |
| 3640 | Trionic Array II | Hard | Array / Dynamic Programming | [View](./3640.%20Trionic%20Array%20II/) |
| 3643 | Flip Square Submatrix Vertically | Easy | Array / Matrix / Simulation | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | Graph / Shortest Path / Heap (Priority Queue) / Dynamic Programming | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | Array / Matrix / Graph / Shortest Path / Heap (Priority Queue) / Dynamic Programming | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |
| 3653 | XOR After Range Multiplication Queries I | Medium | Array / Math / Simulation | [View](./3653.%20XOR%20After%20Range%20Multiplication%20Queries%20I/) |
| 3655 | XOR After Range Multiplication Queries II | Hard | Array / Math / Simulation / Square Root Decomposition | [View](./3655.%20XOR%20After%20Range%20Multiplication%20Queries%20II/) |
| 3629 | Minimum Jumps to Reach End via Prime Teleportation | Medium | Array / BFS / Graph / Math | [View](./3629.%20Minimum%20Jumps%20to%20Reach%20End%20via%20Prime%20Teleportation/) |
| 3660 | Jump Game IX | Medium | Array / Monotonic Stack / Dynamic Programming | [View](./3660.%20Jump%20Game%20IX/) |
| 3661 | Maximum Walls Destroyed by Robots | Hard | Array / Binary Search / Dynamic Programming / Sorting | [View](./3661.%20Maximum%20Walls%20Destroyed%20by%20Robots/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | String / BFS / Math / Greedy | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |
| 3689 | Maximum Total Subarray Value I | Medium | Array | [View](./3689.%20Maximum%20Total%20Subarray%20Value%20I/) |
| 3691 | Maximum Total Subarray Value II | Hard | Array | [View](./3691.%20Maximum%20Total%20Subarray%20Value%20II/) |
| 3699 | Number of ZigZag Arrays I | Hard | Array / Dynamic Programming / Prefix Sum | [View](./3699.%20Number%20of%20ZigZag%20Arrays%20I/) |
| 3700 | Number of ZigZag Arrays II | Hard | Array / Dynamic Programming / Matrix Exponentiation / Graph | [View](./3700.%20Number%20of%20ZigZag%20Arrays%20II/) |
| 3713 | Longest Balanced Substring I | Medium | String / Hash Table / Counting | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |
| 3714 | Longest Balanced Substring II | Medium | String / Hash Table / Prefix Sum | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |
| 3719 | Longest Balanced Subarray I | Medium | Array / Hash Table / Sliding Window | [View](./3719.%20Longest%20Balanced%20Subarray%20I/) |
| 3721 | Longest Balanced Subarray II | Hard | Array / Hash Table / Sliding Window / Segment Tree / Prefix Sum | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |
| 3737 | Count Subarrays With Majority Element I | Medium | Array / Prefix Sum | [View](./3737.%20Count%20Subarrays%20With%20Majority%20Element%20I/) |
| 3739 | Count Subarrays With Majority Element II | Hard | Array / Prefix Sum / Binary Tree / Coordinate Compression | [View](./3739.%20Count%20Subarrays%20With%20Majority%20Element%20II/) |
| 3740 | Minimum Distance Between Three Equal Elements I | Easy | Array / Hash Table / Counting | [View](./3740.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20I/) |
| 3741 | Minimum Distance Between Three Equal Elements II | Medium | Array / Hash Table / Counting | [View](./3741.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20II/) |
| 3742 | Maximum Path Score in a Grid | Medium | Array / Dynamic Programming / Matrix | [View](./3742.%20Maximum%20Path%20Score%20in%20a%20Grid/) |
| 3751 | Total Waviness of Numbers in Range I | Medium | Math / Enumeration | [View](./3751.%20Total%20Waviness%20of%20Numbers%20in%20Range%20I/) |
| 3753 | Total Waviness of Numbers in Range II | Hard | Math / Digit DP / Dynamic Programming | [View](./3753.%20Total%20Waviness%20of%20Numbers%20in%20Range%20II/) |
| 3761 | Minimum Absolute Distance Between Mirror Pairs | Medium | Array / Hash Table / Math | [View](./3761.%20Minimum%20Absolute%20Distance%20Between%20Mirror%20Pairs/) |
| 3783 | Mirror Distance of an Integer | Easy | Math | [View](./3783.%20Mirror%20Distance%20of%20an%20Integer/) |
| 3838 | Weighted Word Mapping | Easy | Array / String / Math | [View](./3838.%20Weighted%20Word%20Mapping/) |

---

## By Category

### Array
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 33 | Search in Rotated Sorted Array | Medium | [View](./33.%20Search%20in%20Rotated%20Sorted%20Array/) |
| 48 | Rotate Image | Medium | [View](./48.%20Rotate%20Image/) |
| 66 | Plus One | Easy | [View](./66.%20Plus%20One/) |
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 153 | Find Minimum in Rotated Sorted Array | Medium | [View](./153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/) |
| 154 | Find Minimum in Rotated Sorted Array II | Hard | [View](./154.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array%20II/) |
| 396 | Rotate Function | Medium | [View](./396.%20Rotate%20Function/) |
| 744 | Find Smallest Letter Greater Than Target | Easy | [View](./744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 961 | N-Repeated Element in Size 2N Array | Easy | [View](./961.%20N-Repeated%20Element%20in%20Size%202N%20Array/) |
| 1200 | Minimum Absolute Difference | Easy | [View](./1200.%20Minimum%20Absolute%20Difference/) |
| 1266 | Minimum Time Visiting All Points | Easy | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 1292 | Maximum Side Length of a Square with Sum less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1306 | Jump Game III | Medium | [View](./1306.%20Jump%20Game%20III/) |
| 1340 | Jump Game V | Hard | [View](./1340.%20Jump%20Game%20V/) |
| 1345 | Jump Game IV | Hard | [View](./1345.%20Jump%20Game%20IV/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1356 | Sort Integers by The Number of 1 Bits | Easy | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 1390 | Four Divisors | Medium | [View](./1390.%20Four%20Divisors/) |
| 1458 | Max Dot Product of Two Subsequences | Hard | [View](./1458.%20Max%20Dot%20Product%20of%20Two%20Subsequences/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1582 | Special Positions in a Binary Matrix | Easy | [View](./1582.%20Special%20Positions%20in%20a%20Binary%20Matrix/) |
| 1594 | Maximum Non Negative Product in a Matrix | Medium | [View](./1594.%20Maximum%20Non%20Negative%20Product%20in%20a%20Matrix/) |
| 1665 | Minimum Initial Energy to Finish Tasks | Hard | [View](./1665.%20Minimum%20Initial%20Energy%20to%20Finish%20Tasks/) |
| 1674 | Minimum Moves to Make Array Complementary | Medium | [View](./1674.%20Minimum%20Moves%20to%20Make%20Array%20Complementary/) |
| 1722 | Minimize Hamming Distance After Swap Operations | Medium | [View](./1722.%20Minimize%20Hamming%20Distance%20After%20Swap%20Operations/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1732 | Find the Highest Altitude | Easy | [View](./1732.%20Find%20the%20Highest%20Altitude/) |
| 1752 | Check if Array Is Sorted and Rotated | Easy | [View](./1752.%20Check%20if%20Array%20Is%20Sorted%20and%20Rotated/) |
| 1833 | Maximum Ice Cream Bars | Medium | [View](./1833.%20Maximum%20Ice%20Cream%20Bars/) |
| 1848 | Minimum Distance to the Target Element | Easy | [View](./1848.%20Minimum%20Distance%20to%20the%20Target%20Element/) |
| 1855 | Maximum Distance Between a Pair of Values | Medium | [View](./1855.%20Maximum%20Distance%20Between%20a%20Pair%20of%20Values/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
| 1895 | Largest Magic Square | Medium | [View](./1895.%20Largest%20Magic%20Square/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 1975 | Maximum Matrix Sum | Medium | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 1980 | Find Unique Binary String | Medium | [View](./1980.%20Find%20Unique%20Binary%20String/) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | Easy | [View](./1984.%20Minimum%20Difference%20Between%20Highest%20and%20Lowest%20of%20K%20Scores/) |
| 2033 | Minimum Operations to Make a Uni-Value Grid | Medium | [View](./2033.%20Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/) |
| 2078 | Two Furthest Houses With Different Colors | Easy | [View](./2078.%20Two%20Furthest%20Houses%20With%20Different%20Colors/) |
| 2161 | Partition Array According to Given Pivot | Easy | [View](./2161.%20Partition%20Array%20According%20to%20Given%20Pivot/) |
| 2402 | Meeting Rooms III | Hard | [View](./2402.%20Meeting%20Rooms%20III/) |
| 2452 | Words Within Two Edits of Dictionary | Medium | [View](./2452.%20Words%20Within%20Two%20Edits%20of%20Dictionary/) |
| 2463 | Minimum Total Distance Traveled | Hard | [View](./2463.%20Minimum%20Total%20Distance%20Traveled/) |
| 2515 | Shortest Distance to Target String in a Circular Array | Easy | [View](./2515.%20Shortest%20Distance%20to%20Target%20String%20in%20a%20Circular%20Array/) |
| 2540 | Minimum Common Value | Easy | [View](./2540.%20Minimum%20Common%20Value/) |
| 2553 | Separate the Digits in an Array | Easy | [View](./2553.%20Separate%20the%20Digits%20in%20an%20Array/) |
| 2574 | Left and Right Sum Differences | Easy | [View](./2574.%20Left%20and%20Right%20Sum%20Differences/) |
| 2615 | Sum of Distances | Medium | [View](./2615.%20Sum%20of%20Distances/) |
| 2657 | Find the Prefix Common Array of Two Arrays | Medium | [View](./2657.%20Find%20the%20Prefix%20Common%20Array%20of%20Two%20Arrays/) |
| 2751 | Robot Collisions | Hard | [View](./2751.%20Robot%20Collisions/) |
| 2784 | Check if Array is Good | Easy | [View](./2784.%20Check%20if%20Array%20is%20Good/) |
| 2906 | Construct Product Matrix | Medium | [View](./2906.%20Construct%20Product%20Matrix/) |
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
| 3161 | Block Placement Queries | Hard | [View](./3161.%20Block%20Placement%20Queries/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3225 | Maximum Score From Grid Operations | Hard | [View](./3225.%20Maximum%20Score%20From%20Grid%20Operations/) |
| 3300 | Minimum Element After Replacement With Digit Sum | Easy | [View](./3300.%20Minimum%20Element%20After%20Replacement%20With%20Digit%20Sum/) |
| 3314 | Construct the Minimum Bitwise Array I | Easy | [View](./3314.%20Construct%20the%20Minimum%20Bitwise%20Array%20I/) |
| 3315 | Construct the Minimum Bitwise Array II | Medium | [View](./3315.%20Construct%20the%20Minimum%20Bitwise%20Array%20II/) |
| 3379 | Transformed Array | Easy | [View](./3379.%20Transformed%20Array/) |
| 3418 | Maximum Amount of Money Robot Can Earn | Medium | [View](./3418.%20Maximum%20Amount%20of%20Money%20Robot%20Can%20Earn/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |
| 3464 | Maximize the Distance Between Points on a Square | Hard | [View](./3464.%20Maximize%20the%20Distance%20Between%20Points%20on%20a%20Square/) |
| 3488 | Closest Equal Element Queries | Medium | [View](./3488.%20Closest%20Equal%20Element%20Queries/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3546 | Equal Sum Grid Partition I | Medium | [View](./3546.%20Equal%20Sum%20Grid%20Partition%20I/) |
| 3548 | Equal Sum Grid Partition II | Hard | [View](./3548.%20Equal%20Sum%20Grid%20Partition%20II/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3629 | Minimum Jumps to Reach End via Prime Teleportation | Medium | [View](./3629.%20Minimum%20Jumps%20to%20Reach%20End%20via%20Prime%20Teleportation/) |
| 3634 | Minimum Removals to Balance Array | Medium | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |
| 3637 | Trionic Array I | Easy | [View](./3637.%20Trionic%20Array%20I/) |
| 3640 | Trionic Array II | Hard | [View](./3640.%20Trionic%20Array%20II/) |
| 3643 | Flip Square Submatrix Vertically | Easy | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |
| 3653 | XOR After Range Multiplication Queries I | Medium | [View](./3653.%20XOR%20After%20Range%20Multiplication%20Queries%20I/) |
| 3655 | XOR After Range Multiplication Queries II | Hard | [View](./3655.%20XOR%20After%20Range%20Multiplication%20Queries%20II/) |
| 3660 | Jump Game IX | Medium | [View](./3660.%20Jump%20Game%20IX/) |
| 3661 | Maximum Walls Destroyed by Robots | Hard | [View](./3661.%20Maximum%20Walls%20Destroyed%20by%20Robots/) |
| 3689 | Maximum Total Subarray Value I | Medium | [View](./3689.%20Maximum%20Total%20Subarray%20Value%20I/) |
| 3691 | Maximum Total Subarray Value II | Hard | [View](./3691.%20Maximum%20Total%20Subarray%20Value%20II/) |
| 3699 | Number of ZigZag Arrays I | Hard | [View](./3699.%20Number%20of%20ZigZag%20Arrays%20I/) |
| 3700 | Number of ZigZag Arrays II | Hard | [View](./3700.%20Number%20of%20ZigZag%20Arrays%20II/) |
| 3719 | Longest Balanced Subarray I | Medium | [View](./3719.%20Longest%20Balanced%20Subarray%20I/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |
| 3737 | Count Subarrays With Majority Element I | Medium | [View](./3737.%20Count%20Subarrays%20With%20Majority%20Element%20I/) |
| 3739 | Count Subarrays With Majority Element II | Hard | [View](./3739.%20Count%20Subarrays%20With%20Majority%20Element%20II/) |
| 3740 | Minimum Distance Between Three Equal Elements I | Easy | [View](./3740.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20I/) |
| 3741 | Minimum Distance Between Three Equal Elements II | Medium | [View](./3741.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20II/) |
| 3742 | Maximum Path Score in a Grid | Medium | [View](./3742.%20Maximum%20Path%20Score%20in%20a%20Grid/) |
| 3761 | Minimum Absolute Distance Between Mirror Pairs | Medium | [View](./3761.%20Minimum%20Absolute%20Distance%20Between%20Mirror%20Pairs/) |
| 3838 | Weighted Word Mapping | Easy | [View](./3838.%20Weighted%20Word%20Mapping/) |

### BFS
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1161 | Maximum Level Sum of a Binary Tree | Medium | [View](./1161.%20Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/) |
| 1306 | Jump Game III | Medium | [View](./1306.%20Jump%20Game%20III/) |
| 1345 | Jump Game IV | Hard | [View](./1345.%20Jump%20Game%20IV/) |
| 1391 | Check if There is a Valid Path in a Grid | Medium | [View](./1391.%20Check%20if%20There%20is%20a%20Valid%20Path%20in%20a%20Grid/) |
| 1871 | Jump Game VII | Medium | [View](./1871.%20Jump%20Game%20VII/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 3558 | Number of Ways to Assign Edge Weights I | Medium | [View](./3558.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20I/) |
| 3629 | Minimum Jumps to Reach End via Prime Teleportation | Medium | [View](./3629.%20Minimum%20Jumps%20to%20Reach%20End%20via%20Prime%20Teleportation/) |
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
| 33 | Search in Rotated Sorted Array | Medium | [View](./33.%20Search%20in%20Rotated%20Sorted%20Array/) |
| 153 | Find Minimum in Rotated Sorted Array | Medium | [View](./153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/) |
| 154 | Find Minimum in Rotated Sorted Array II | Hard | [View](./154.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array%20II/) |
| 744 | Find Smallest Letter Greater Than Target | Easy | [View](./744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target/) |
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 3161 | Block Placement Queries | Hard | [View](./3161.%20Block%20Placement%20Queries/) |
| 3296 | Minimum Number of Seconds to Make Mountain Height Zero | Medium | [View](./3296.%20Minimum%20Number%20of%20Seconds%20to%20Make%20Mountain%20Height%20Zero/) || 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |
| 3464 | Maximize the Distance Between Points on a Square | Hard | [View](./3464.%20Maximize%20the%20Distance%20Between%20Points%20on%20a%20Square/) |
| 3488 | Closest Equal Element Queries | Medium | [View](./3488.%20Closest%20Equal%20Element%20Queries/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |
| 3635 | Earliest Finish Time for Land and Water Rides II | Medium | [View](./3635.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20II/) |
| 3661 | Maximum Walls Destroyed by Robots | Hard | [View](./3661.%20Maximum%20Walls%20Destroyed%20by%20Robots/) |

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
| 3739 | Count Subarrays With Majority Element II | Hard | [View](./3739.%20Count%20Subarrays%20With%20Majority%20Element%20II/) |

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
| 3739 | Count Subarrays With Majority Element II | Hard | [View](./3739.%20Count%20Subarrays%20With%20Majority%20Element%20II/) |

### Counting
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1189 | Maximum Number of Balloons | Easy | [View](./1189.%20Maximum%20Number%20of%20Balloons/) |
| 1356 | Sort Integers by The Number of 1 Bits | Easy | [View](./1356.%20Sort%20Integers%20by%20The%20Number%20of%201%20Bits/) |
| 1833 | Maximum Ice Cream Bars | Medium | [View](./1833.%20Maximum%20Ice%20Cream%20Bars/) |
| 2784 | Check if Array is Good | Easy | [View](./2784.%20Check%20if%20Array%20is%20Good/) |
| 2840 | Check if Strings Can be Made Equal With Operations II | Medium | [View](./2840.%20Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20II/) |
| 3120 | Count the Number of Special Characters I | Easy | [View](./3120.%20Count%20the%20Number%20of%20Special%20Characters%20I/) |
| 3121 | Count the Number of Special Characters II | Medium | [View](./3121.%20Count%20the%20Number%20of%20Special%20Characters%20II/) |
| 3713 | Longest Balanced Substring I | Medium | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |
| 3740 | Minimum Distance Between Three Equal Elements I | Easy | [View](./3740.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20I/) |
| 3741 | Minimum Distance Between Three Equal Elements II | Medium | [View](./3741.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20II/) |

### DFS
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 110 | Balanced Binary Tree | Easy | [View](./110.%20Balanced%20Binary%20Tree/) |
| 865 | Smallest Subtree with all the Deepest Nodes | Medium | [View](./865.%20Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/) |
| 1022 | Sum of Root To Leaf Binary Numbers | Easy | [View](./1022.%20Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/) |
| 1306 | Jump Game III | Medium | [View](./1306.%20Jump%20Game%20III/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1340 | Jump Game V | Hard | [View](./1340.%20Jump%20Game%20V/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 1391 | Check if There is a Valid Path in a Grid | Medium | [View](./1391.%20Check%20if%20There%20is%20a%20Valid%20Path%20in%20a%20Grid/) |
| 1559 | Detect Cycles in 2D Grid | Medium | [View](./1559.%20Detect%20Cycles%20in%202D%20Grid/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |

### Design
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1622 | Fancy Sequence | Hard | [View](./1622.%20Fancy%20Sequence/) |
| 2069 | Walking Robot Simulation II | Medium | [View](./2069.%20Walking%20Robot%20Simulation%20II/) |

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
| 396 | Rotate Function | Medium | [View](./396.%20Rotate%20Function/) |
| 712 | Minimum ASCII Delete Sum for Two Strings | Medium | [View](./712.%20Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings/) |
| 788 | Rotated Digits | Medium | [View](./788.%20Rotated%20Digits/) |
| 799 | Champagne Tower | Medium | [View](./799.%20Champagne%20Tower/) |
| 1320 | Minimum Distance to Type a Word Using Two Fingers | Hard | [View](./1320.%20Minimum%20Distance%20to%20Type%20a%20Word%20Using%20Two%20Fingers/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1340 | Jump Game V | Hard | [View](./1340.%20Jump%20Game%20V/) |
| 1411 | Number of Ways to Paint N × 3 Grid | Hard | [View](./1411.%20Number%20of%20Ways%20to%20Paint%20N%20×%203%20Grid/) |
| 1458 | Max Dot Product of Two Subsequences | Hard | [View](./1458.%20Max%20Dot%20Product%20of%20Two%20Subsequences/) |
| 1594 | Maximum Non Negative Product in a Matrix | Medium | [View](./1594.%20Maximum%20Non%20Negative%20Product%20in%20a%20Matrix/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |
| 2463 | Minimum Total Distance Traveled | Hard | [View](./2463.%20Minimum%20Total%20Distance%20Traveled/) |
| 2573 | Find the String with LCP | Hard | [View](./2573.%20Find%20the%20String%20with%20LCP/) |
| 2770 | Maximum Number of Jumps to Reach the Last Index | Medium | [View](./2770.%20Maximum%20Number%20of%20Jumps%20to%20Reach%20the%20Last%20Index/) |
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3129 | Find All Possible Stable Binary Arrays I | Medium | [View](./3129.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20I/) |
| 3130 | Find All Possible Stable Binary Arrays II | Hard | [View](./3130.%20Find%20All%20Possible%20Stable%20Binary%20Arrays%20II/) |
| 3225 | Maximum Score From Grid Operations | Hard | [View](./3225.%20Maximum%20Score%20From%20Grid%20Operations/) |
| 3418 | Maximum Amount of Money Robot Can Earn | Medium | [View](./3418.%20Maximum%20Amount%20of%20Money%20Robot%20Can%20Earn/) |
| 3640 | Trionic Array II | Hard | [View](./3640.%20Trionic%20Array%20II/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |
| 3660 | Jump Game IX | Medium | [View](./3660.%20Jump%20Game%20IX/) |
| 3661 | Maximum Walls Destroyed by Robots | Hard | [View](./3661.%20Maximum%20Walls%20Destroyed%20by%20Robots/) |
| 3699 | Number of ZigZag Arrays I | Hard | [View](./3699.%20Number%20of%20ZigZag%20Arrays%20I/) |
| 3700 | Number of ZigZag Arrays II | Hard | [View](./3700.%20Number%20of%20ZigZag%20Arrays%20II/) |
| 3742 | Maximum Path Score in a Grid | Medium | [View](./3742.%20Maximum%20Path%20Score%20in%20a%20Grid/) |
| 3753 | Total Waviness of Numbers in Range II | Hard | [View](./3753.%20Total%20Waviness%20of%20Numbers%20in%20Range%20II/) |

### Enumeration
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3751 | Total Waviness of Numbers in Range I | Medium | [View](./3751.%20Total%20Waviness%20of%20Numbers%20in%20Range%20I/) |

### Geometry
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1266 | Minimum Time Visiting All Points | Easy | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 1344 | Angle Between Hands of a Clock | Medium | [View](./1344.%20Angle%20Between%20Hands%20of%20a%20Clock/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |
| 3464 | Maximize the Distance Between Points on a Square | Hard | [View](./3464.%20Maximize%20the%20Distance%20Between%20Points%20on%20a%20Square/) |

### Graph
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1345 | Jump Game IV | Hard | [View](./1345.%20Jump%20Game%20IV/) |
| 1391 | Check if There is a Valid Path in a Grid | Medium | [View](./1391.%20Check%20if%20There%20is%20a%20Valid%20Path%20in%20a%20Grid/) |
| 2976 | Minimum Cost to Convert String I | Medium | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |
| 3629 | Minimum Jumps to Reach End via Prime Teleportation | Medium | [View](./3629.%20Minimum%20Jumps%20to%20Reach%20End%20via%20Prime%20Teleportation/) |
| 3650 | Minimum Cost Path with Edge Reversals | Medium | [View](./3650.%20Minimum%20Cost%20Path%20with%20Edge%20Reversals/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |
| 3700 | Number of ZigZag Arrays II | Hard | [View](./3700.%20Number%20of%20ZigZag%20Arrays%20II/) |

### Greedy
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 761 | Special Binary String | Hard | [View](./761.%20Special%20Binary%20String/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1665 | Minimum Initial Energy to Finish Tasks | Hard | [View](./1665.%20Minimum%20Initial%20Energy%20to%20Finish%20Tasks/) |
| 1674 | Minimum Moves to Make Array Complementary | Medium | [View](./1674.%20Minimum%20Moves%20to%20Make%20Array%20Complementary/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 1758 | Minimum Changes To Make Alternating Binary String | Easy | [View](./1758.%20Minimum%20Changes%20To%20Make%20Alternating%20Binary%20String/) |
| 1833 | Maximum Ice Cream Bars | Medium | [View](./1833.%20Maximum%20Ice%20Cream%20Bars/) |
| 1840 | Maximum Building Height | Hard | [View](./1840.%20Maximum%20Building%20Height/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1975 | Maximum Matrix Sum | Medium | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 2126 | Destroying Asteroids | Medium | [View](./2126.%20Destroying%20Asteroids/) |
| 2144 | Minimum Cost of Buying Candies With Discount | Easy | [View](./2144.%20Minimum%20Cost%20of%20Buying%20Candies%20With%20Discount/) |
| 2943 | Maximize Area of Square Hole in Grid | Medium | [View](./2943.%20Maximize%20Area%20of%20Square%20Hole%20in%20Grid/) |
| 3010 | Divide an Array Into Subarrays With Minimum Cost I | Easy | [View](./3010.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20I/) |
| 3075 | Maximize Happiness of Selected Children | Medium | [View](./3075.%20Maximize%20Happiness%20of%20Selected%20Children/) |
| 3474 | Lexicographically Smallest Generated String | Hard | [View](./3474.%20Lexicographically%20Smallest%20Generated%20String/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3600 | Maximize Spanning Tree Stability with Upgrades | Hard | [View](./3600.%20Maximize%20Spanning%20Tree%20Stability%20with%20Upgrades/) |
| 3614 | Process String with Special Operations II | Hard | [View](./3614.%20Process%20String%20with%20Special%20Operations%20II/) |
| 3633 | Earliest Finish Time for Land and Water Rides I | Easy | [View](./3633.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20I/) |
| 3635 | Earliest Finish Time for Land and Water Rides II | Medium | [View](./3635.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20II/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |

### Hash Table
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 756 | Pyramid Transition Matrix | Medium | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 961 | N-Repeated Element in Size 2N Array | Easy | [View](./961.%20N-Repeated%20Element%20in%20Size%202N%20Array/) |
| 1189 | Maximum Number of Balloons | Easy | [View](./1189.%20Maximum%20Number%20of%20Balloons/) |
| 1345 | Jump Game IV | Hard | [View](./1345.%20Jump%20Game%20IV/) |
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |
| 2196 | Create Binary Tree From Descriptions | Medium | [View](./2196.%20Create%20Binary%20Tree%20From%20Descriptions/) |
| 2615 | Sum of Distances | Medium | [View](./2615.%20Sum%20of%20Distances/) |
| 2784 | Check if Array is Good | Easy | [View](./2784.%20Check%20if%20Array%20is%20Good/) |
| 2840 | Check if Strings Can be Made Equal With Operations II | Medium | [View](./2840.%20Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20II/) |
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 3120 | Count the Number of Special Characters I | Easy | [View](./3120.%20Count%20the%20Number%20of%20Special%20Characters%20I/) |
| 3488 | Closest Equal Element Queries | Medium | [View](./3488.%20Closest%20Equal%20Element%20Queries/) |
| 3548 | Equal Sum Grid Partition II | Hard | [View](./3548.%20Equal%20Sum%20Grid%20Partition%20II/) |
| 3713 | Longest Balanced Substring I | Medium | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |
| 3714 | Longest Balanced Substring II | Medium | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |
| 3719 | Longest Balanced Subarray I | Medium | [View](./3719.%20Longest%20Balanced%20Subarray%20I/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |
| 3740 | Minimum Distance Between Three Equal Elements I | Easy | [View](./3740.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20I/) |
| 3741 | Minimum Distance Between Three Equal Elements II | Medium | [View](./3741.%20Minimum%20Distance%20Between%20Three%20Equal%20Elements%20II/) |
| 3761 | Minimum Absolute Distance Between Mirror Pairs | Medium | [View](./3761.%20Minimum%20Absolute%20Distance%20Between%20Mirror%20Pairs/) |

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

### Linked List
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 61 | Rotate List | Medium | [View](./61.%20Rotate%20List/) |
| 2095 | Delete the Middle Node of a Linked List | Easy | [View](./2095.%20Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/) |
| 2130 | Maximum Twin Sum of a Linked List | Medium | [View](./2130.%20Maximum%20Twin%20Sum%20of%20a%20Linked%20List/) |

### Lowest Common Ancestor
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3559 | Number of Ways to Assign Edge Weights II | Hard | [View](./3559.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20II/) |

### Math
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 48 | Rotate Image | Medium | [View](./48.%20Rotate%20Image/) |
| 66 | Plus One | Easy | [View](./66.%20Plus%20One/) |
| 67 | Add Binary | Easy | [View](./67.%20Add%20Binary/) |
| 396 | Rotate Function | Medium | [View](./396.%20Rotate%20Function/) |
| 762 | Prime Number of Set Bits in Binary Representation | Easy | [View](./762.%20Prime%20Number%20of%20Set%20Bits%20in%20Binary%20Representation/) |
| 788 | Rotated Digits | Medium | [View](./788.%20Rotated%20Digits/) |
| 799 | Champagne Tower | Medium | [View](./799.%20Champagne%20Tower/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 1266 | Minimum Time Visiting All Points | Easy | [View](./1266.%20Minimum%20Time%20Visiting%20All%20Points/) |
| 1344 | Angle Between Hands of a Clock | Medium | [View](./1344.%20Angle%20Between%20Hands%20of%20a%20Clock/) |
| 1390 | Four Divisors | Medium | [View](./1390.%20Four%20Divisors/) |
| 1411 | Number of Ways to Paint N × 3 Grid | Hard | [View](./1411.%20Number%20of%20Ways%20to%20Paint%20N%20×%203%20Grid/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1622 | Fancy Sequence | Hard | [View](./1622.%20Fancy%20Sequence/) |
| 1680 | Concatenation of Consecutive Binary Numbers | Medium | [View](./1680.%20Concatenation%20of%20Consecutive%20Binary%20Numbers/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 1840 | Maximum Building Height | Hard | [View](./1840.%20Maximum%20Building%20Height/) |
| 2033 | Minimum Operations to Make a Uni-Value Grid | Medium | [View](./2033.%20Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/) |
| 2069 | Walking Robot Simulation II | Medium | [View](./2069.%20Walking%20Robot%20Simulation%20II/) |
| 2553 | Separate the Digits in an Array | Easy | [View](./2553.%20Separate%20the%20Digits%20in%20an%20Array/) |
| 2833 | Furthest Point From Origin | Easy | [View](./2833.%20Furthest%20Point%20From%20Origin/) |
| 2906 | Construct Product Matrix | Medium | [View](./2906.%20Construct%20Product%20Matrix/) |
| 2975 | Maximum Square Area by Removing Fences From a Field | Medium | [View](./2975.%20Maximum%20Square%20Area%20by%20Removing%20Fences%20From%20a%20Field/) |
| 3047 | Find the Largest Area of Square Inside Two Rectangles | Medium | [View](./3047.%20Find%20the%20Largest%20Area%20of%20Square%20Inside%20Two%20Rectangles/) |
| 3296 | Minimum Number of Seconds to Make Mountain Height Zero | Medium | [View](./3296.%20Minimum%20Number%20of%20Seconds%20to%20Make%20Mountain%20Height%20Zero/) |
| 3300 | Minimum Number of Seconds to Make Mountain Height Zero II | Hard | [View](./3300.%20Minimum%20Number%20of%20Seconds%20to%20Make%20Mountain%20Height%20Zero%20II/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3558 | Number of Ways to Assign Edge Weights I | Medium | [View](./3558.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20I/) |
| 3559 | Number of Ways to Assign Edge Weights II | Hard | [View](./3559.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20II/) |
| 3629 | Minimum Jumps to Reach End via Prime Teleportation | Medium | [View](./3629.%20Minimum%20Jumps%20to%20Reach%20End%20via%20Prime%20Teleportation/) |
| 3653 | XOR After Range Multiplication Queries I | Medium | [View](./3653.%20XOR%20After%20Range%20Multiplication%20Queries%20I/) |
| 3655 | XOR After Range Multiplication Queries II | Hard | [View](./3655.%20XOR%20After%20Range%20Multiplication%20Queries%20II/) |
| 3666 | Minimum Operations to Equalize Binary String | Hard | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |
| 3751 | Total Waviness of Numbers in Range I | Medium | [View](./3751.%20Total%20Waviness%20of%20Numbers%20in%20Range%20I/) |
| 3753 | Total Waviness of Numbers in Range II | Hard | [View](./3753.%20Total%20Waviness%20of%20Numbers%20in%20Range%20II/) |
| 3761 | Minimum Absolute Distance Between Mirror Pairs | Medium | [View](./3761.%20Minimum%20Absolute%20Distance%20Between%20Mirror%20Pairs/) |
| 3783 | Mirror Distance of an Integer | Easy | [View](./3783.%20Mirror%20Distance%20of%20an%20Integer/) |
| 3838 | Weighted Word Mapping | Easy | [View](./3838.%20Weighted%20Word%20Mapping/) |

### Matrix
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 48 | Rotate Image | Medium | [View](./48.%20Rotate%20Image/) |
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 840 | Magic Squares In Grid | Medium | [View](./840.%20Magic%20Squares%20In%20Grid/) |
| 1292 | Maximum Side Length of a Square with Sum Less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1351 | Count Negative Numbers in a Sorted Matrix | Easy | [View](./1351.%20Count%20Negative%20Numbers%20in%20a%20Sorted%20Matrix/) |
| 1391 | Check if There is a Valid Path in a Grid | Medium | [View](./1391.%20Check%20if%20There%20is%20a%20Valid%20Path%20in%20a%20Grid/) |
| 1536 | Minimum Swaps to Arrange a Binary Grid | Medium | [View](./1536.%20Minimum%20Swaps%20to%20Arrange%20a%20Binary%20Grid/) |
| 1559 | Detect Cycles in 2D Grid | Medium | [View](./1559.%20Detect%20Cycles%20in%202D%20Grid/) |
| 1582 | Special Positions in a Binary Matrix | Easy | [View](./1582.%20Special%20Positions%20in%20a%20Binary%20Matrix/) |
| 1594 | Maximum Non Negative Product in a Matrix | Medium | [View](./1594.%20Maximum%20Non%20Negative%20Product%20in%20a%20Matrix/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1861 | Rotating the Box | Medium | [View](./1861.%20Rotating%20the%20Box/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
| 1886 | Determine Whether Matrix Can Be Obtained By Rotation | Easy | [View](./1886.%20Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/) |
| 1895 | Largest Magic Square | Medium | [View](./1895.%20Largest%20Magic%20Square/) |
| 1914 | Cyclically Rotating a Grid | Medium | [View](./1914.%20Cyclically%20Rotating%20a%20Grid/) |
| 1970 | Last Day Where You Can Still Cross | Hard | [View](./1970.%20Last%20Day%20Where%20You%20Can%20Still%20Cross/) |
| 1975 | Maximum Matrix Sum | Medium | [View](./1975.%20Maximum%20Matrix%20Sum/) |
| 2033 | Minimum Operations to Make a Uni-Value Grid | Medium | [View](./2033.%20Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/) |
| 2075 | Decode the Slanted Ciphertext | Medium | [View](./2075.%20Decode%20the%20Slanted%20Ciphertext/) |
| 2573 | Find the String with LCP | Hard | [View](./2573.%20Find%20the%20String%20with%20LCP/) |
| 2906 | Construct Product Matrix | Medium | [View](./2906.%20Construct%20Product%20Matrix/) |
| 2946 | Matrix Similarity After Cyclic Shifts | Easy | [View](./2946.%20Matrix%20Similarity%20After%20Cyclic%20Shifts/) |
| 3070 | Count Submatrices with Top-Left Element and Sum Less Than k | Medium | [View](./3070.%20Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3225 | Maximum Score From Grid Operations | Hard | [View](./3225.%20Maximum%20Score%20From%20Grid%20Operations/) |
| 3418 | Maximum Amount of Money Robot Can Earn | Medium | [View](./3418.%20Maximum%20Amount%20of%20Money%20Robot%20Can%20Earn/) |
| 3546 | Equal Sum Grid Partition I | Medium | [View](./3546.%20Equal%20Sum%20Grid%20Partition%20I/) |
| 3548 | Equal Sum Grid Partition II | Hard | [View](./3548.%20Equal%20Sum%20Grid%20Partition%20II/) || 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3643 | Flip Square Submatrix Vertically | Easy | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |
| 3651 | Minimum Cost Path with Teleportations | Hard | [View](./3651.%20Minimum%20Cost%20Path%20with%20Teleportations/) |
| 3742 | Maximum Path Score in a Grid | Medium | [View](./3742.%20Maximum%20Path%20Score%20in%20a%20Grid/) |

### Matrix Exponentiation
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3700 | Number of ZigZag Arrays II | Hard | [View](./3700.%20Number%20of%20ZigZag%20Arrays%20II/) |

### Monotonic Stack
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 3660 | Jump Game IX | Medium | [View](./3660.%20Jump%20Game%20IX/) |

### Ordered Set
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3013 | Divide an Array Into Subarrays With Minimum Cost II | Hard | [View](./3013.%20Divide%20an%20Array%20Into%20Subarrays%20With%20Minimum%20Cost%20II/) |
| 3161 | Block Placement Queries | Hard | [View](./3161.%20Block%20Placement%20Queries/) |

### Prefix Sum
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1292 | Maximum Side Length of a Square with Sum less than or Equal to Threshold | Medium | [View](./1292.%20Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/) |
| 1674 | Minimum Moves to Make Array Complementary | Medium | [View](./1674.%20Minimum%20Moves%20to%20Make%20Array%20Complementary/) |
| 1732 | Find the Highest Altitude | Easy | [View](./1732.%20Find%20the%20Highest%20Altitude/) |
| 1871 | Jump Game VII | Medium | [View](./1871.%20Jump%20Game%20VII/) |
| 1878 | Get Biggest Three Rhombus Sums in a Grid | Medium | [View](./1878.%20Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/) |
| 1895 | Largest Magic Square | Medium | [View](./1895.%20Largest%20Magic%20Square/) |
| 2483 | Minimum Penalty for a Shop | Medium | [View](./2483.%20Minimum%20Penalty%20for%20a%20Shop/) |
| 2574 | Left and Right Sum Differences | Easy | [View](./2574.%20Left%20and%20Right%20Sum%20Differences/) |
| 2615 | Sum of Distances | Medium | [View](./2615.%20Sum%20of%20Distances/) |
| 2906 | Construct Product Matrix | Medium | [View](./2906.%20Construct%20Product%20Matrix/) |
| 3070 | Count Submatrices with Top-Left Element and Sum Less Than k | Medium | [View](./3070.%20Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/) |
| 3212 | Count Submatrices With Equal Frequency of X and Y | Medium | [View](./3212.%20Count%20Submatrices%20With%20Equal%20Frequency%20of%20X%20and%20Y/) |
| 3225 | Maximum Score From Grid Operations | Hard | [View](./3225.%20Maximum%20Score%20From%20Grid%20Operations/) |
| 3546 | Equal Sum Grid Partition I | Medium | [View](./3546.%20Equal%20Sum%20Grid%20Partition%20I/) |
| 3548 | Equal Sum Grid Partition II | Hard | [View](./3548.%20Equal%20Sum%20Grid%20Partition%20II/) |
| 3699 | Number of ZigZag Arrays I | Hard | [View](./3699.%20Number%20of%20ZigZag%20Arrays%20I/) |
| 3714 | Longest Balanced Substring II | Medium | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |
| 3721 | Longest Balanced Subarray II | Hard | [View](./3721.%20Longest%20Balanced%20Subarray%20II/) |
| 3737 | Count Subarrays With Majority Element I | Medium | [View](./3737.%20Count%20Subarrays%20With%20Majority%20Element%20I/) |
| 3739 | Count Subarrays With Majority Element II | Hard | [View](./3739.%20Count%20Subarrays%20With%20Majority%20Element%20II/) |

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
| 657 | Robot Return to Origin | Easy | [View](./657.%20Robot%20Return%20to%20Origin/) |
| 796 | Rotate String | Easy | [View](./796.%20Rotate%20String/) |
| 799 | Champagne Tower | Medium | [View](./799.%20Champagne%20Tower/) |
| 874 | Walking Robot Simulation | Medium | [View](./874.%20Walking%20Robot%20Simulation/) |
| 1680 | Concatenation of Consecutive Binary Numbers | Medium | [View](./1680.%20Concatenation%20of%20Consecutive%20Binary%20Numbers/) |
| 1861 | Rotating the Box | Medium | [View](./1861.%20Rotating%20the%20Box/) |
| 1886 | Determine Whether Matrix Can Be Obtained By Rotation | Easy | [View](./1886.%20Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/) |
| 1914 | Cyclically Rotating a Grid | Medium | [View](./1914.%20Cyclically%20Rotating%20a%20Grid/) |
| 2069 | Walking Robot Simulation II | Medium | [View](./2069.%20Walking%20Robot%20Simulation%20II/) |
| 2075 | Decode the Slanted Ciphertext | Medium | [View](./2075.%20Decode%20the%20Slanted%20Ciphertext/) |
| 2402 | Meeting Rooms III | Hard | [View](./2402.%20Meeting%20Rooms%20III/) |
| 2751 | Robot Collisions | Hard | [View](./2751.%20Robot%20Collisions/) |
| 2839 | Check if Strings Can be Made Equal With Operations I | Easy | [View](./2839.%20Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20I/) |
| 2946 | Matrix Similarity After Cyclic Shifts | Easy | [View](./2946.%20Matrix%20Similarity%20After%20Cyclic%20Shifts/) |
| 3379 | Transformed Array | Easy | [View](./3379.%20Transformed%20Array/) |
| 3507 | Minimum Pair Removal to Sort Array I | Easy | [View](./3507.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20I/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3510 | Minimum Pair Removal to Sort Array II | Hard | [View](./3510.%20Minimum%20Pair%20Removal%20to%20Sort%20Array%20II/) |
| 3612 | Process String with Special Operations I | Medium | [View](./3612.%20Process%20String%20with%20Special%20Operations%20I/) |
| 3614 | Process String with Special Operations II | Hard | [View](./3614.%20Process%20String%20with%20Special%20Operations%20II/) |
| 3633 | Earliest Finish Time for Land and Water Rides I | Easy | [View](./3633.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20I/) |
| 3635 | Earliest Finish Time for Land and Water Rides II | Medium | [View](./3635.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20II/) |
| 3643 | Flip Square Submatrix Vertically | Easy | [View](./3643.%20Flip%20Square%20Submatrix%20Vertically/) |
| 3653 | XOR After Range Multiplication Queries I | Medium | [View](./3653.%20XOR%20After%20Range%20Multiplication%20Queries%20I/) |
| 3655 | XOR After Range Multiplication Queries II | Hard | [View](./3655.%20XOR%20After%20Range%20Multiplication%20Queries%20II/) |

### Sliding Window
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1871 | Jump Game VII | Medium | [View](./1871.%20Jump%20Game%20VII/) |
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
| 1665 | Minimum Initial Energy to Finish Tasks | Hard | [View](./1665.%20Minimum%20Initial%20Energy%20to%20Finish%20Tasks/) |
| 1727 | Largest Submatrix With Rearrangements | Medium | [View](./1727.%20Largest%20Submatrix%20With%20Rearrangements/) |
| 1833 | Maximum Ice Cream Bars | Medium | [View](./1833.%20Maximum%20Ice%20Cream%20Bars/) |
| 1840 | Maximum Building Height | Hard | [View](./1840.%20Maximum%20Building%20Height/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 1984 | Minimum Difference Between Highest and Lowest of K Scores | Easy | [View](./1984.%20Minimum%20Difference%20Between%20Highest%20and%20Lowest%20of%20K%20Scores/) |
| 2033 | Minimum Operations to Make a Uni-Value Grid | Medium | [View](./2033.%20Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/) |
| 2126 | Destroying Asteroids | Medium | [View](./2126.%20Destroying%20Asteroids/) |
| 2144 | Minimum Cost of Buying Candies With Discount | Easy | [View](./2144.%20Minimum%20Cost%20of%20Buying%20Candies%20With%20Discount/) |
| 2402 | Meeting Rooms III | Hard | [View](./2402.%20Meeting%20Rooms%20III/) |
| 2463 | Minimum Total Distance Traveled | Hard | [View](./2463.%20Minimum%20Total%20Distance%20Traveled/) |
| 2751 | Robot Collisions | Hard | [View](./2751.%20Robot%20Collisions/) |
| 2943 | Maximize Area of Square Hole in Grid | Medium | [View](./2943.%20Maximize%20Area%20of%20Square%20Hole%20in%20Grid/) |
| 3075 | Maximize Happiness of Selected Children | Medium | [View](./3075.%20Maximize%20Happiness%20of%20Selected%20Children/) |
| 3453 | Separate Squares I | Medium | [View](./3453.%20Separate%20Squares%20I/) |
| 3454 | Separate Squares II | Hard | [View](./3454.%20Separate%20Squares%20II/) |
| 3464 | Maximize the Distance Between Points on a Square | Hard | [View](./3464.%20Maximize%20the%20Distance%20Between%20Points%20on%20a%20Square/) |
| 3567 | Minimum Absolute Difference in Sliding Submatrix | Medium | [View](./3567.%20Minimum%20Absolute%20Difference%20in%20Sliding%20Submatrix/) |
| 3634 | Minimum Removals to Balance Array | Medium | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |
| 3635 | Earliest Finish Time for Land and Water Rides II | Medium | [View](./3635.%20Earliest%20Finish%20Time%20for%20Land%20and%20Water%20Rides%20II/) |
| 3661 | Maximum Walls Destroyed by Robots | Hard | [View](./3661.%20Maximum%20Walls%20Destroyed%20by%20Robots/) |

### Square Root Decomposition
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3655 | XOR After Range Multiplication Queries II | Hard | [View](./3655.%20XOR%20After%20Range%20Multiplication%20Queries%20II/) |

### Stack
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 85 | Maximal Rectangle | Hard | [View](./85.%20Maximal%20Rectangle/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |
| 2751 | Robot Collisions | Hard | [View](./2751.%20Robot%20Collisions/) |

### String
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 67 | Add Binary | Easy | [View](./67.%20Add%20Binary/) |
| 657 | Robot Return to Origin | Easy | [View](./657.%20Robot%20Return%20to%20Origin/) |
| 696 | Count Binary Substrings | Easy | [View](./696.%20Count%20Binary%20Substrings/) |
| 712 | Minimum ASCII Delete Sum for Two Strings | Medium | [View](./712.%20Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings/) |
| 756 | Pyramid Transition Matrix | Medium | [View](./756.%20Pyramid%20Transition%20Matrix/) |
| 761 | Special Binary String | Hard | [View](./761.%20Special%20Binary%20String/) |
| 796 | Rotate String | Easy | [View](./796.%20Rotate%20String/) |
| 1189 | Maximum Number of Balloons | Easy | [View](./1189.%20Maximum%20Number%20of%20Balloons/) |
| 1320 | Minimum Distance to Type a Word Using Two Fingers | Hard | [View](./1320.%20Minimum%20Distance%20to%20Type%20a%20Word%20Using%20Two%20Fingers/) |
| 1404 | Number of Steps to Reduce a Number in Binary Representation to One | Medium | [View](./1404.%20Number%20of%20Steps%20to%20Reduce%20a%20Number%20in%20Binary%20Representation%20to%20One/) |
| 1415 | The k-th Lexicographical String of All Happy Strings of Length n | Medium | [View](./1415.%20The%20k-th%20Lexicographical%20String%20of%20All%20Happy%20Strings%20of%20Length%20n/) |
| 1461 | Check If a String Contains All Binary Codes of Size K | Medium | [View](./1461.%20Check%20If%20a%20String%20Contains%20All%20Binary%20Codes%20of%20Size%20K/) |
| 1545 | Find Kth Bit in Nth Binary String | Medium | [View](./1545.%20Find%20Kth%20Bit%20in%20Nth%20Binary%20String/) |
| 1653 | Minimum Deletions to Make String Balanced | Medium | [View](./1653.%20Minimum%20Deletions%20to%20Make%20String%20Balanced/) |
| 1689 | Partitioning Into Minimum Number Of Deci-Binary Numbers | Medium | [View](./1689.%20Partitioning%20Into%20Minimum%20Number%20Of%20Deci-Binary%20Numbers/) |
| 1758 | Minimum Changes To Make Alternating Binary String | Easy | [View](./1758.%20Minimum%20Changes%20To%20Make%20Alternating%20Binary%20String/) |
| 1784 | Check if Binary String Has at Most One Segment of Ones | Easy | [View](./1784.%20Check%20if%20Binary%20String%20Has%20at%20Most%20One%20Segment%20of%20Ones/) |
| 1871 | Jump Game VII | Medium | [View](./1871.%20Jump%20Game%20VII/) |
| 1888 | Minimum Number of Flips to Make the Binary String Alternating | Medium | [View](./1888.%20Minimum%20Number%20of%20Flips%20to%20Make%20the%20Binary%20String%20Alternating/) |
| 1980 | Find Unique Binary String | Medium | [View](./1980.%20Find%20Unique%20Binary%20String/) |
| 2075 | Decode the Slanted Ciphertext | Medium | [View](./2075.%20Decode%20the%20Slanted%20Ciphertext/) |
| 2452 | Words Within Two Edits of Dictionary | Medium | [View](./2452.%20Words%20Within%20Two%20Edits%20of%20Dictionary/) |
| 2483 | Minimum Penalty for a Shop | Medium | [View](./2483.%20Minimum%20Penalty%20for%20a%20Shop/) |
| 2515 | Shortest Distance to Target String in a Circular Array | Easy | [View](./2515.%20Shortest%20Distance%20to%20Target%20String%20in%20a%20Circular%20Array/) |
| 2573 | Find the String with LCP | Hard | [View](./2573.%20Find%20the%20String%20with%20LCP/) |
| 2833 | Furthest Point From Origin | Easy | [View](./2833.%20Furthest%20Point%20From%20Origin/) |
| 2839 | Check if Strings Can be Made Equal With Operations I | Easy | [View](./2839.%20Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20I/) |
| 2840 | Check if Strings Can be Made Equal With Operations II | Medium | [View](./2840.%20Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20II/) |
| 2976 | Minimum Cost to Convert String I | Medium | [View](./2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) |
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3093 | Longest Common Suffix Queries | Hard | [View](./3093.%20Longest%20Common%20Suffix%20Queries/) |
| 3120 | Count the Number of Special Characters I | Easy | [View](./3120.%20Count%20the%20Number%20of%20Special%20Characters%20I/) |
| 3121 | Count the Number of Special Characters II | Medium | [View](./3121.%20Count%20the%20Number%20of%20Special%20Characters%20II/) |
| 3474 | Lexicographically Smallest Generated String | Hard | [View](./3474.%20Lexicographically%20Smallest%20Generated%20String/) |
| 3612 | Process String with Special Operations I | Medium | [View](./3612.%20Process%20String%20with%20Special%20Operations%20I/) |
| 3614 | Process String with Special Operations II | Hard | [View](./3614.%20Process%20String%20with%20Special%20Operations%20II/) |S
| 3666 | Minimum Operations to Equalize Binary String | Hard | [View](./3666.%20Minimum%20Operations%20to%20Equalize%20Binary%20String/) |
| 3713 | Longest Balanced Substring I | Medium | [View](./3713.%20Longest%20Balanced%20Substring%20I/) |
| 3714 | Longest Balanced Substring II | Medium | [View](./3714.%20Longest%20Balanced%20Substring%20II/) |
| 3838 | Weighted Word Mapping | Easy | [View](./3838.%20Weighted%20Word%20Mapping/) |

### Suffix
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 3093 | Longest Common Suffix Queries | Hard | [View](./3093.%20Longest%20Common%20Suffix%20Queries/) |

### Tree
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 110 | Balanced Binary Tree | Easy | [View](./110.%20Balanced%20Binary%20Tree/) |
| 1022 | Sum of Root To Leaf Binary Numbers | Easy | [View](./1022.%20Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/) |
| 865 | Smallest Subtree with all the Deepest Nodes | Medium | [View](./865.%20Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/) |
| 1161 | Maximum Level Sum of a Binary Tree | Medium | [View](./1161.%20Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/) |
| 1339 | Maximum Product of Splitted Binary Tree | Medium | [View](./1339.%20Maximum%20Product%20of%20Splitted%20Binary%20Tree/) |
| 1382 | Balance a Binary Search Tree | Medium | [View](./1382.%20Balance%20a%20Binary%20Search%20Tree/) |
| 2196 | Create Binary Tree From Descriptions | Medium | [View](./2196.%20Create%20Binary%20Tree%20From%20Descriptions/) |
| 3558 | Number of Ways to Assign Edge Weights I | Medium | [View](./3558.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20I/) |
| 3559 | Number of Ways to Assign Edge Weights II | Hard | [View](./3559.%20Number%20of%20Ways%20to%20Assign%20Edge%20Weights%20II/) |

### Trie
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 2977 | Minimum Cost to Convert String II | Hard | [View](./2977.%20Minimum%20Cost%20to%20Convert%20String%20II/) |
| 3043 | Find the Length of the Longest Common Prefix | Medium | [View](./3043.%20Find%20the%20Length%20of%20the%20Longest%20Common%20Prefix/) |
| 3093 | Longest Common Suffix Queries | Hard | [View](./3093.%20Longest%20Common%20Suffix%20Queries/) |
 
### Two Pointers
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 61 | Rotate List | Medium | [View](./61.%20Rotate%20List/) |
| 696 | Count Binary Substrings | Easy | [View](./696.%20Count%20Binary%20Substrings/) |
| 1855 | Maximum Distance Between a Pair of Values | Medium | [View](./1855.%20Maximum%20Distance%20Between%20a%20Pair%20of%20Values/) |
| 1877 | Minimize Maximum Pair Sum in Array | Medium | [View](./1877.%20Minimize%20Maximum%20Pair%20Sum%20in%20Array/) |
| 2095 | Delete the Middle Node of a Linked List | Medium | [View](./2095.%20Delete%20the%20Middle%20Node%20of%20a%20Linked%20List/) |
| 2130 | Maximum Twin Sum of a Linked List | Medium | [View](./2130.%20Maximum%20Twin%20Sum%20of%20a%20Linked%20List/) |
| 2540 | Minimum Common Value | Easy | [View](./2540.%20Minimum%20Common%20Value/) |
| 3634 | Minimum Removals to Balance Array | Medium | [View](./3634.%20Minimum%20Removals%20to%20Balance%20Array/) |

### Union Find
| # | Title | Difficulty | Solution |
|---|--------|------------|---------|
| 1722 | Minimize Hamming Distance After Swap Operations | Medium | [View](./1722.%20Minimize%20Hamming%20Distance%20After%20Swap%20Operations/) |
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

