class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        // If target is negative,
        // it is impossible.
        if (target < 0)
            return -1;

        // If target is 0,
        // we have to remove the whole array.
        if (target == 0)
            return n;

        int left = 0;
        int sum = 0;
        int maxLength = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            // Window sum is too large
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a valid subarray
            if (sum == target) {
                maxLength = max(
                    maxLength,
                    right - left + 1
                );
            }
        }

        if (maxLength == -1)
            return -1;

        return n - maxLength;
    }
};
