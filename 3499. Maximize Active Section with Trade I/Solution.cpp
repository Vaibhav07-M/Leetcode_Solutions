class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for (char c : s) ones += (c == '1');

        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char,int>> runs;
        for (int i = 0; i < m; ) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        // runs look like: 1-run,0-run,1-run,...
        // choose a removable 1-run surrounded by 0-runs
        // then merge the adjacent 0-runs with the removed 1-run
        for (int i = 2; i + 2 < runs.size(); i += 2) {
            if (runs[i].first != '1') continue;

            int oneLen = runs[i].second;
            int zeroLen = runs[i - 1].second + runs[i + 1].second;

            ans = max(ans, ones - oneLen + zeroLen + oneLen);
        }

        return ans;
    }
};