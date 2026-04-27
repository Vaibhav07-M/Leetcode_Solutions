class Solution {
public:
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // directions: up, right, down, left
        vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        
        // mapping for each type
        vector<vector<int>> type = {
            {},
            {1,3},    // 1
            {0,2},    // 2
            {3,2},    // 3
            {1,2},    // 4
            {3,0},    // 5
            {1,0}     // 6
        };
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            if(x == m-1 && y == n-1) return true;
            
            for(int d : type[grid[x][y]]) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(vis[nx][ny]) continue;
                
                // check reverse connection
                int rev = (d + 2) % 4;
                for(int nd : type[grid[nx][ny]]) {
                    if(nd == rev) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }
        
        return false;
    }
};