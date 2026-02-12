class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int freq[26] = {0};

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mn = 1000000000;
                int mx = 0;
                bool valid = true;

                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        mn = min(mn, freq[k]);
                        mx = max(mx, freq[k]);
                    }
                }

                if(mn == mx) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
