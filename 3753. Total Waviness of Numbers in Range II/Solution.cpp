class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        const auto& count = [&](long long x) {
            auto encode = [&](int i, int prev, int prev2, bool zero, bool tight) {
                long long key = i;
                key = key * (10 + 1) + (prev + 1);
                key = key * (10 + 1) + (prev2 + 1);
                key = key * 2 + (zero ? 1 : 0);
                key = key * 2 + (tight ? 1 : 0);
                return key;
            };

            const auto& s = to_string(x);
            vector<pair<long long, long long>> lookup(size(s) * (10 + 1) * (10 + 1) * 2 * 2, {-1, -1});
            const auto dp = [&](this auto&& dp, int i, int prev, int prev2, bool zero, bool tight) -> pair<long long, long long> {
                if (i == size(s)) {
                    return {1, 0};
                }
                long long key = encode(i, prev, prev2, zero, tight);
                if (lookup[key].first == -1) {
                    long long cnt = 0, w = 0;
                    const auto& mx = tight ? s[i] - '0' : 9;
                    for (int d = 0; d <= mx; ++d) {
                        const auto& new_tight = tight && (d == s[i] - '0');
                        const auto& new_zero = zero && (d == 0);
                        const auto& new_prev2 = prev;
                        const auto& new_prev = !new_zero ? d : -1;
                        const auto& [new_cnt, nw] = dp(i + 1, new_prev, new_prev2, new_zero, new_tight);
                        cnt += new_cnt;
                        if (!zero && prev2 != -1 && ((prev2 < prev && prev > d) || (prev2 > prev && prev < d))) {
                            w += new_cnt;
                        }
                        w += nw;
                    }
                    lookup[key] = {cnt, w};
                }
                return lookup[key];
            };

            return dp(0, -1, -1, true, true).second;
        };

        return count(num2) - count(num1 - 1);
    }
};