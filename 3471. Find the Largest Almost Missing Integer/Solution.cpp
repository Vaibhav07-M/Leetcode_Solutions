class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // count[x] = number of subarrays of size k
        // that contain x
        vector<int> count(51, 0);

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            // To make sure a number is counted only once
            // inside the current window
            vector<bool> seen(51, false);

            for (int j = i; j < i + k; j++) {
                int x = nums[j];

                if (!seen[x]) {
                    count[x]++;
                    seen[x] = true;
                }
            }
        }

        int ans = -1;

        // Find the largest number appearing
        // in exactly one subarray
        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};
