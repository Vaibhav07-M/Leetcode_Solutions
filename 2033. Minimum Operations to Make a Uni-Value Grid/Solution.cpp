class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> arr;
        
        // Step 1: flatten
        for(auto &row : grid) {
            for(int val : row) {
                arr.push_back(val);
            }
        }
        
        // Step 2: check validity
        int mod = arr[0] % x;
        for(int val : arr) {
            if(val % x != mod) return -1;
        }
        
        // Step 3: sort
        sort(arr.begin(), arr.end());
        
        // Step 4: take median
        int median = arr[arr.size() / 2];
        
        // Step 5: compute operations
        int ops = 0;
        for(int val : arr) {
            ops += abs(val - median) / x;
        }
        
        return ops;
    }
};