class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newdp(k, 0);

            int x = num % k;

            // Start a new subarray with only num
            newdp[x]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * x) % k;
                    newdp[newRemainder] += dp[r];
                }
            }

            // All subarrays ending here contribute to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += newdp[r];
            }

            dp = newdp;
        }

        return ans;
    }
};
