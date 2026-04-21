class Solution {
public:
    
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();
        
        // Step 1: DSU
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }
        
        // Step 2: Group indices
        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }
        
        int ans = 0;
        
        // Step 3: Process each group
        for(auto &p : groups) {
            unordered_map<int,int> freq;
            
            // Count source frequencies
            for(int idx : p.second) {
                freq[source[idx]]++;
            }
            
            // Match with target
            for(int idx : p.second) {
                if(freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++; // mismatch
                }
            }
        }
        
        return ans;
    }
};