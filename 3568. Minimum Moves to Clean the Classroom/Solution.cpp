class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int cnt = 0;

        // Give every litter an index
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        // No litter
        if (cnt == 0)
            return 0;

        int totalMask = 1 << cnt;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMask, false)
                )
            )
        );

        // row, col, current energy, collected mask
        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, 0});
        visited[sx][sy][energy][0] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [x, y, curEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == totalMask - 1)
                    return moves;

                // Cannot move with zero energy
                if (curEnergy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Outside grid
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n)
                        continue;

                    // Obstacle
                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = curEnergy - 1;
                    int newMask = mask;

                    // Reset energy
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        int bit = id[nx][ny];
                        newMask |= (1 << bit);
                    }

                    // Already visited this exact state
                    if (visited[nx][ny][newEnergy][newMask])
                        continue;

                    visited[nx][ny][newEnergy][newMask] = true;

                    q.push({
                        nx,
                        ny,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};
