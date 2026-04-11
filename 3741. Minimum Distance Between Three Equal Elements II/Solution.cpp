class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> pos;
        
        // Store positions
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Process each value
        for (auto &p : pos) {
            auto &v = p.second;
            
            if (v.size() < 3) continue;
            
            // Check consecutive triples
            for (int i = 0; i + 2 < v.size(); i++) {
                ans = min(ans, 2 * (v[i+2] - v[i]));
            }
        }
        
        return (ans == INT_MAX ? -1 : ans);
    }
};