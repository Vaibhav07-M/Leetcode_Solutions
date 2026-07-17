class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[d] = number of elements divisible by d
        vector<long long> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                cnt[d] += freq[j];
        }

        // exact[d] = number of pairs with gcd exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long pairs = cnt[d] * (cnt[d] - 1) / 2;
            for (int j = d + d; j <= mx; j += d)
                pairs -= exact[j];
            exact[d] = pairs;
        }

        // prefix counts in sorted gcd array
        vector<long long> pref(mx + 1, 0);
        for (int d = 1; d <= mx; d++)
            pref[d] = pref[d - 1] + exact[d];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            int lo = 1, hi = mx;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (pref[mid] > q)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            ans.push_back(lo);
        }

        return ans;
    }
};