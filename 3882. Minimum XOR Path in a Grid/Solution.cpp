class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // possible[i][j][x] indicates whether XOR value x
        // can be obtained on a path ending at cell (i, j).
        vector<vector<vector<bool>>> possible(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        possible[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int value = grid[i][j];

                // Paths coming from above
                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (possible[i - 1][j][x]) {
                            possible[i][j][x ^ value] = true;
                        }
                    }
                }

                // Paths coming from the left
                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (possible[i][j - 1][x]) {
                            possible[i][j][x ^ value] = true;
                        }
                    }
                }
            }
        }

        // Find the smallest XOR value at the destination
        for (int x = 0; x < 1024; x++) {
            if (possible[m - 1][n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
