class Solution {
public:
    static const int LIM = 1000000;

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIM) return LIM + 1;
        }
        return min(res, (long long)LIM + 1);
    }

    long long countWays(vector<int>& cnt) {
        int tot = 0;
        for (int x : cnt) tot += x;

        long long ways = 1;
        int rem = tot;

        for (int x : cnt) {
            if (x == 0) continue;
            ways *= C(rem, x);
            if (ways > LIM) return LIM + 1;
            rem -= x;
        }
        return min(ways, (long long)LIM + 1);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string mid = "";
        vector<int> half(26, 0);

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k) return "";

        string left = "";
        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};