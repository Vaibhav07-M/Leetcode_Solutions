class Solution {
public:
    
    bool isPrime(int x) {
        if(x < 2) return false;
        
        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) return false;
        }
        
        return true;
    }
    
    int minJumps(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return 0;
        
        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++) {
            
            int val = nums[i];
            
            // collect prime factors
            for(int p = 2; p * p <= val; p++) {
                if(val % p == 0) {
                    
                    mp[p].push_back(i);
                    
                    while(val % p == 0)
                        val /= p;
                }
            }
            
            if(val > 1)
                mp[val].push_back(i);
        }
        
        vector<bool> vis(n, false);
        queue<pair<int,int>> q;
        
        q.push({0,0});
        vis[0] = true;
        
        while(!q.empty()) {
            
            auto [i, steps] = q.front();
            q.pop();
            
            if(i == n-1)
                return steps;
            
            // adjacent left
            if(i-1 >= 0 && !vis[i-1]) {
                vis[i-1] = true;
                q.push({i-1, steps+1});
            }
            
            // adjacent right
            if(i+1 < n && !vis[i+1]) {
                vis[i+1] = true;
                q.push({i+1, steps+1});
            }
            
            // teleport
            int val = nums[i];
            
            if(isPrime(val)) {
                
                for(int nxt : mp[val]) {
                    if(!vis[nxt]) {
                        vis[nxt] = true;
                        q.push({nxt, steps+1});
                    }
                }
                
                // IMPORTANT optimization
                mp[val].clear();
            }
        }
        
        return -1;
    }
};