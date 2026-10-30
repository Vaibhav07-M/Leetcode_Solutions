class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        // Build the adjacency list
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // dist[node][count] = minimum cost to reach this state
        const long long INF = LLONG_MAX / 2;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {cost, node, consecutive character count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, node, count] = pq.top();
            pq.pop();

            // Skip outdated states
            if (cost != dist[node][count]) {
                continue;
            }

            // Destination reached
            if (node == n - 1) {
                return (int)cost;
            }

            // Explore neighboring nodes
            for (auto [next, weight] : adj[node]) {
                int newCount;

                if (labels[next] == labels[node]) {
                    newCount = count + 1;
                } else {
                    newCount = 1;
                }

                // Reject paths exceeding k consecutive characters
                if (newCount > k) {
                    continue;
                }

                long long newCost = cost + weight;

                if (newCost < dist[next][newCount]) {
                    dist[next][newCount] = newCost;
                    pq.push({newCost, next, newCount});
                }
            }
        }

        return -1;
    }
};
