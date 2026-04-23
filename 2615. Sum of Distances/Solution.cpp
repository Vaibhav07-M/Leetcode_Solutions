class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        // Step 1: group indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        // Step 2: process each group
        for(auto &p : mp) {
            auto &v = p.second;
            int m = v.size();
            
            vector<long long> prefix(m+1, 0);
            
            // prefix sum of indices
            for(int i = 0; i < m; i++) {
                prefix[i+1] = prefix[i] + v[i];
            }
            
            for(int i = 0; i < m; i++) {
                long long idx = v[i];
                
                // left side
                long long left = idx * i - prefix[i];
                
                // right side
                long long right = (prefix[m] - prefix[i+1]) - idx * (m - i - 1);
                
                ans[idx] = left + right;
            }
        }
        
        return ans;
    }
};