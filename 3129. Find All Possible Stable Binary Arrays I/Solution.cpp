class Solution {
public:
    const int MOD = 1e9 + 7;
    int memo[201][201][2][201];

    int solve(int z, int o, int last, int cnt, int limit) {
        if(z == 0 && o == 0) return 1;

        if(memo[z][o][last][cnt] != -1)
            return memo[z][o][last][cnt];

        long long ans = 0;

        if(z > 0) {
            if(last == 0) {
                if(cnt < limit)
                    ans += solve(z - 1, o, 0, cnt + 1, limit);
            } 
            else {
                ans += solve(z - 1, o, 0, 1, limit);
            }
        }

        if(o > 0) {
            if(last == 1) {
                if(cnt < limit)
                    ans += solve(z, o - 1, 1, cnt + 1, limit);
            } 
            else {
                ans += solve(z, o - 1, 1, 1, limit);
            }
        }

        return memo[z][o][last][cnt] = ans % MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(memo, -1, sizeof(memo));

        long long ans = 0;

        if(zero > 0)
            ans += solve(zero - 1, one, 0, 1, limit);

        if(one > 0)
            ans += solve(zero, one - 1, 1, 1, limit);

        return ans % MOD;
    }
};