class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        
        int n = nums.size();
        
        vector<int> diff(2 * limit + 2, 0);
        
        for(int i = 0; i < n / 2; i++) {
            
            int x = nums[i];
            int y = nums[n - 1 - i];
            
            int a = min(x, y);
            int b = max(x, y);
            
            // initially 2 moves everywhere
            
            // 1 move starts
            diff[a + 1] -= 1;
            
            // 0 moves at x+y
            diff[x + y] -= 1;
            diff[x + y + 1] += 1;
            
            // back to 2 moves
            diff[b + limit + 1] += 1;
        }
        
        int ans = INT_MAX;
        
        int curr = n; // initially 2 moves per pair
        
        for(int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }
        
        return ans;
    }
};