class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        // Try every possible row shift
        for (int dr = -(n - 1); dr <= n - 1; dr++) {

            // Try every possible column shift
            for (int dc = -(n - 1); dc <= n - 1; dc++) {

                int overlap = 0;

                // Check every cell of img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        if (img1[i][j] == 0)
                            continue;

                        int ni = i + dr;
                        int nj = j + dc;

                        // Check if shifted position is inside img2
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < n &&
                            img2[ni][nj] == 1) {
                            
                            overlap++;
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};
