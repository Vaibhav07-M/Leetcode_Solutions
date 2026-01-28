class Solution {
public:
    int minCost(vector<vector<int>>& grid,int k) {
        int m=grid.size();
        int n=grid[0].size();
        const long long INF=1e18;

        auto id=[&](int r,int c) {
            return r*n+c;
        };

        int total=m*n;

        vector<vector<long long>> dist(k+1,vector<long long>(total,INF));

        vector<pair<int,int>> cells;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cells.push_back({grid[i][j],id(i,j)});
            }
        }
        sort(cells.begin(),cells.end());

        vector<int> ptr(k+1,0);

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[0][0]=0;
        pq.push({0,0,0});

        while(!pq.empty()) {
            auto [cost,u,t]=pq.top();
            pq.pop();

            if(cost!=dist[t][u]) {
                continue;
            }

            int r=u/n;
            int c=u%n;

            // normal moves
            if(r+1<m) {
                int v=id(r+1,c);
                if(dist[t][v]>cost+grid[r+1][c]) {
                    dist[t][v]=cost+grid[r+1][c];
                    pq.push({dist[t][v],v,t});
                }
            }

            if(c+1<n) {
                int v=id(r,c+1);
                if(dist[t][v]>cost+grid[r][c+1]) {
                    dist[t][v]=cost+grid[r][c+1];
                    pq.push({dist[t][v],v,t});
                }
            }

            // teleport (lazy expansion)
            if(t<k) {
                while(ptr[t+1]<cells.size() &&
                      cells[ptr[t+1]].first<=grid[r][c]) {

                    int v=cells[ptr[t+1]].second;
                    if(dist[t+1][v]>cost) {
                        dist[t+1][v]=cost;
                        pq.push({cost,v,t+1});
                    }
                    ptr[t+1]++;
                }
            }
        }

        long long ans=INF;
        int target=id(m-1,n-1);
        for(int t=0;t<=k;t++) {
            ans=min(ans,dist[t][target]);
        }

        if(ans==INF) {
            return -1;
        }
        return ans;
    }
};
