class Solution {
public:
    char processStr(string s, long long k) {

        const long long LIM = 1000000000000000LL;

        int n = s.size();

        vector<long long> len(n + 1, 0);

        for(int i = 0; i < n; i++) {

            char c = s[i];

            if('a' <= c && c <= 'z') {
                len[i + 1] = min(LIM + 1, len[i] + 1);
            }
            else if(c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if(c == '#') {
                len[i + 1] = min(LIM + 1, len[i] * 2);
            }
            else { // %
                len[i + 1] = len[i];
            }
        }

        if(k >= len[n]) return '.';

        for(int i = n - 1; i >= 0; i--) {

            char c = s[i];

            long long prev = len[i];
            long long cur  = len[i + 1];

            if('a' <= c && c <= 'z') {

                if(k == prev)
                    return c;
            }
            else if(c == '*') {

                // surviving positions unchanged

            }
            else if(c == '#') {

                if(k >= prev)
                    k -= prev;
            }
            else { // %

                if(cur > 0)
                    k = cur - 1 - k;
            }
        }

        return '.';
    }
};