class Solution {
public:
    
    int m, n;
    
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        
        vis[x][y] = true;
        
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(auto &d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(grid[nx][ny] != grid[x][y]) continue;
            
            // skip parent
            if(nx == px && ny == py) continue;
            
            if(vis[nx][ny]) return true; // cycle found
            
            if(dfs(nx, ny, x, y, grid, vis)) return true;
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};