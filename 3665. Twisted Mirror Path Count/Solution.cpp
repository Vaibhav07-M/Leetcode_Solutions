class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;

    vector<vector<int>> grid;

    // memo[i][j][dir] stores the final cell
    vector<vector<vector<int>>> memo;

    // dir = 0 means moving right
    // dir = 1 means moving down

    int solve(int i, int j, int dir) {

        // Outside the grid
        if (i >= m || j >= n) {
            return -1;
        }

        // Already calculated
        if (memo[i][j][dir] != -2) {
            return memo[i][j][dir];
        }

        // Empty cell: stop here
        if (grid[i][j] == 0) {
            return memo[i][j][dir] = i * n + j;
        }

        // Mirror: change direction
        if (dir == 0) {
            return memo[i][j][dir] =
                solve(i + 1, j, 1);
        }
        else {
            return memo[i][j][dir] =
                solve(i, j + 1, 0);
        }
    }

    int uniquePaths(vector<vector<int>>& grid) {

        this->grid = grid;

        m = grid.size();
        n = grid[0].size();

        memo.assign(
            m,
            vector<vector<int>>(
                n, vector<int>(2, -2)
            )
        );

        vector<vector<int>> dp(
            m, vector<int>(n, 0)
        );

        // Start from top-left
        dp[0][0] = 1;

        // Process cells row by row
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // Mirror cells are not stopping points
                if (grid[i][j] == 1) {
                    continue;
                }

                int ways = dp[i][j];

                if (ways == 0) {
                    continue;
                }

                // Try moving right
                int right = solve(i, j + 1, 0);

                if (right != -1) {

                    int x = right / n;
                    int y = right % n;

                    dp[x][y] =
                        (dp[x][y] + ways) % MOD;
                }

                // Try moving down
                int down = solve(i + 1, j, 1);

                if (down != -1) {

                    int x = down / n;
                    int y = down % n;

                    dp[x][y] =
                        (dp[x][y] + ways) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
