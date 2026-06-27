class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Special case for 1
        if (cnt.count(1)) {
            int c = cnt[1];
            ans = max(ans, (c % 2 == 0) ? c - 1 : c);
        }

        for (auto &[start, freq] : cnt) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) {
                    // No center exists
                    len--;
                    break;
                }

                if (cnt[cur] == 1) {
                    // Can use as center
                    len++;
                    break;
                }

                // Use two copies of cur
                len += 2;

                // Prevent overflow before squaring
                if (cur > 1000000000LL / cur) {
                    len--;
                    break;
                }

                cur = cur * cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};