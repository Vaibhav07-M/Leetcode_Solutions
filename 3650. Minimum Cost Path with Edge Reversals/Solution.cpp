class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if(cost > dist[u]) {
                continue;
            }

            for(auto &p : graph[u]) {
                int v = p.first;
                int w = p.second;

                if(dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[n - 1] == INF) {
            return -1;
        }

        return dist[n - 1];
    }
};
