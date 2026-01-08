class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        // dp[i][j] = max dot product using nums1[0..i-1], nums2[0..j-1]
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INT_MIN));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {

                int currentProduct = nums1[i - 1] * nums2[j - 1];

                // Option 1: take both elements
                int takeBoth = currentProduct;
                if (dp[i - 1][j - 1] > 0)
                    takeBoth += dp[i - 1][j - 1];

                // Option 2 & 3: skip one element
                dp[i][j] = max({
                    takeBoth,
                    dp[i - 1][j],
                    dp[i][j - 1]
                });
            }
        }

        return dp[len1][len2];
    }
};
