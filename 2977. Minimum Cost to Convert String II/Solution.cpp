class Solution {
public:
    long long minimumCost(string source,
                          string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        int n = source.size();

        // Collect all unique strings
        unordered_map<string,int> id;
        int idx = 0;

        for(int i = 0; i < original.size(); i++) {
            if(!id.count(original[i])) {
                id[original[i]] = idx++;
            }
            if(!id.count(changed[i])) {
                id[changed[i]] = idx++;
            }
        }

        int m = idx;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));

        for(int i = 0; i < m; i++) {
            dist[i][i] = 0;
        }

        for(int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall on strings
        for(int k = 0; k < m; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < m; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Group transformations by length
        unordered_map<int, vector<pair<string,string>>> byLen;
        for(auto &p : id) {
            int len = p.first.size();
            byLen[len].push_back({p.first, ""});
        }

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {

            // Single character match
            if(source[i] == target[i]) {
                dp[i] = dp[i + 1];
            }

            // Try all substring lengths
            for(auto &entry : byLen) {
                int len = entry.first;

                if(i + len > n) {
                    continue;
                }

                string sSub = source.substr(i, len);
                string tSub = target.substr(i, len);

                if(!id.count(sSub) || !id.count(tSub)) {
                    continue;
                }

                long long c = dist[id[sSub]][id[tSub]];
                if(c == INF) {
                    continue;
                }

                dp[i] = min(dp[i], c + dp[i + len]);
            }
        }

        if(dp[0] >= INF) {
            return -1;
        }

        return dp[0];
    }
};
