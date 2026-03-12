class DSU {
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        int pa=find(a), pb=find(b);
        if(pa==pb) return false;

        if(rank[pa]<rank[pb])
            swap(pa,pb);

        parent[pb]=pa;

        if(rank[pa]==rank[pb])
            rank[pa]++;

        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, int target){

        DSU dsu(n);
        int used = 0;
        int upgrades = 0;

        vector<vector<int>> optional;

        // handle mandatory edges first
        for(auto &e:edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must==1){
                if(s < target) return false;

                if(!dsu.unite(u,v))
                    return false;

                used++;
            }
            else optional.push_back(e);
        }

        // sort optional edges by strength descending
        sort(optional.begin(), optional.end(),
            [](auto &a, auto &b){
                return a[2] > b[2];
            });

        for(auto &e:optional){

            int u=e[0], v=e[1], s=e[2];

            if(dsu.find(u)==dsu.find(v))
                continue;

            if(s >= target){
                dsu.unite(u,v);
                used++;
            }
            else if(2*s >= target && upgrades < k){
                dsu.unite(u,v);
                upgrades++;
                used++;
            }

            if(used == n-1)
                return true;
        }

        return used == n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo = 1;
        int hi = 200000;
        int ans = -1;

        while(lo <= hi){

            int mid = (lo + hi) / 2;

            if(can(n, edges, k, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        return ans;
    }
};