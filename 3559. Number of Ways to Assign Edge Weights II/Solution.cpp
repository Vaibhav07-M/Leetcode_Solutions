class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int LOG = 17 + 1; // enough for 1e5

    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int nxt : adj[node]) {
            if (nxt == parent) continue;

            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int lca(int a, int b) {

        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j))
                a = up[a][j];
        }

        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(
        vector<vector<int>>& edges,
        vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        adj.assign(n + 1, {});
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 1);

        vector<int> ans;

        for (auto &q : queries) {

            int u = q[0];
            int v = q[1];

            int p = lca(u, v);

            long long len =
                depth[u] + depth[v] - 2LL * depth[p];

            if (len == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)modPow(2, len - 1));
            }
        }

        return ans;
    }
};