class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0...i]
        vector<int> best(n, n + 1);

        int left = 0;
        int sum = 0;
        int ans = n + 1;
        int minLength = n + 1;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Shrink window if sum becomes too large
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // We found a subarray with sum = target
            if (sum == target) {
                int len = right - left + 1;

                // If there is a previous non-overlapping subarray,
                // combine their lengths
                if (left > 0 && best[left - 1] != n + 1) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Keep the shortest valid subarray seen so far
                minLength = min(minLength, len);
            }

            best[right] = minLength;
        }

        if (ans == n + 1)
            return -1;

        return ans;
    }
};
