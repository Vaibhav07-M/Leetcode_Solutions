class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<int> up(m), down(m);
        vector<int> newUp(m), newDown(m);
        vector<int> prefUp(m + 1), prefDown(m + 1);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] =
                    (prefUp[i] + up[i]) % MOD;

                prefDown[i + 1] =
                    (prefDown[i] + down[i]) % MOD;
            }

            int totalUp = prefUp[m];

            for (int i = 0; i < m; i++) {

                newUp[i] = prefDown[i];

                newDown[i] =
                    (totalUp - prefUp[i + 1] + MOD) % MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans += up[i];
            ans += down[i];
        }

        return ans % MOD;
    }
};