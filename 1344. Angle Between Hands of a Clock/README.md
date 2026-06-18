# 1344. Angle Between Hands of a Clock

**Difficulty:** `Medium`  
**Tags:** `Math`, `Geometry`

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

[LeetCode — 1344. Angle Between Hands of a Clock](https://leetcode.com/problems/angle-between-hands-of-a-clock/)

---

## Problem Summary

Given two integers:

- `hour` representing the hour hand position.
- `minutes` representing the minute hand position.

Return the **smaller angle** (in degrees) formed between the hour hand and the minute hand of an analog clock.

Answers within `10^-5` of the actual answer are accepted.

---

## Examples

### Example 1
**Input:** `hour = 12, minutes = 30`  
**Output:** `165`

### Example 2
**Input:** `hour = 3, minutes = 30`  
**Output:** `75`

### Example 3
**Input:** `hour = 3, minutes = 15`  
**Output:** `7.5`

---

## Intuition

To find the angle between the clock hands, we first determine the position of each hand.

- The minute hand completes a full circle (`360°`) in `60` minutes, so it moves `6°` every minute.
- The hour hand completes a full circle (`360°`) in `12` hours, so it moves `30°` every hour.
- Since the hour hand moves continuously, it also advances `0.5°` every minute.

After calculating both angles, we find their difference. Since two angles are formed between the hands, we return the smaller one.

---

## Approach

1. Compute the angle of the minute hand:

   ```cpp
   minuteAngle = minutes * 6
   ```

2. Compute the angle of the hour hand:

   ```cpp
   hourAngle = (hour % 12) * 30 + minutes * 0.5
   ```

3. Calculate the absolute difference:

   ```cpp
   diff = abs(hourAngle - minuteAngle)
   ```

4. Return the smaller angle between:

   ```cpp
   diff
   ```

   and

   ```cpp
   360 - diff
   ```

This directly gives the minimum angle between the two clock hands.

---

## Complexity

| Metric | Complexity |
|----------|----------|
| **Time** | `O(1)` |
| **Space** | `O(1)` |

---

## Code (C++)

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {

        double minuteAngle = minutes * 6.0;

        double hourAngle =
            (hour % 12) * 30.0 +
            minutes * 0.5;

        double diff =
            abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};
```

---

## Key Takeaways

- The minute hand moves `6°` per minute.
- The hour hand moves `30°` per hour and `0.5°` per minute.
- Compute both hand positions independently.
- Use the absolute difference between the two angles.
- Return the smaller angle using `min(diff, 360 - diff)`.
- The solution runs in constant time and space.