class Solution {
public:
    int totalRows;
    int totalCols;
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool bfsCheck(vector<vector<int>> &mapState, int startRow, int startCol) {
        
        queue<pair<int,int>> q;
        q.push({startRow, startCol});
        mapState[startRow][startCol] = 1; // mark visited as water-like to block revisits
        
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int row = current.first;
            int col = current.second;
            
            // reached bottom row
            if(row == totalRows - 1)
                return true;
            
            // explore neighbors
            for(auto &step : directions) {
                int nextRow = row + step[0];
                int nextCol = col + step[1];
                
                if(nextRow >= 0 && nextRow < totalRows &&
                   nextCol >= 0 && nextCol < totalCols &&
                   mapState[nextRow][nextCol] == 0) 
                {
                    mapState[nextRow][nextCol] = 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
        
        return false;
    }
    
    bool canWalkOnDay(vector<vector<int>>& cells, int dayIndex) {
        vector<vector<int>> gridState(totalRows, vector<int>(totalCols, 0));
        
        // mark flooded cells for days up to dayIndex
        for(int d = 0; d <= dayIndex; d++) {
            int r = cells[d][0] - 1;
            int c = cells[d][1] - 1;
            gridState[r][c] = 1;
        }
        
        // try BFS from every land cell in top row
        for(int col = 0; col < totalCols; col++) {
            if(gridState[0][col] == 0 && bfsCheck(gridState, 0, col))
                return true;
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        totalRows = row;
        totalCols = col;

        int left = 0;
        int right = cells.size() - 1;
        int lastPossibleDay = 0;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(canWalkOnDay(cells, mid)) {
                lastPossibleDay = mid + 1;
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        
        return lastPossibleDay;
    }
};
