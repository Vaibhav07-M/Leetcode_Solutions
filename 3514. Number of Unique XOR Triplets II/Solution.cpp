class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int x : nums) {
            auto ndp = dp;

            for (int c = 0; c <= 3; c++) {
                for (int v = 0; v < MAXX; v++) {
                    if (!dp[c][v]) continue;

                    if (c + 1 <= 3)
                        ndp[c + 1][v ^ x] = true;

                    if (c + 2 <= 3)
                        ndp[c + 2][v] = true;      // x ^ x = 0

                    if (c + 3 <= 3)
                        ndp[c + 3][v ^ x] = true;  // x ^ x ^ x = x
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;
        for (int v = 0; v < MAXX; v++)
            if (dp[3][v]) ans++;

        return ans;
    }
};