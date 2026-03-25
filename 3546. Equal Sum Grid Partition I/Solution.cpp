class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        
        // Total sum
        for(auto &row : grid) {
            for(auto &val : row) {
                total += val;
            }
        }
        
        // If odd → impossible
        if(total % 2 != 0) return false;
        
        long long target = total / 2;
        
        // Check horizontal cuts
        long long sum = 0;
        for(int i = 0; i < m - 1; i++) { // ensure non-empty
            for(int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if(sum == target) return true;
        }
        
        // Check vertical cuts
        sum = 0;
        for(int j = 0; j < n - 1; j++) { // ensure non-empty
            for(int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            if(sum == target) return true;
        }
        
        return false;
    }
};