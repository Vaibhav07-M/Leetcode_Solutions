class Solution {
private:
    bool isvalid(vector<vector<int>> &grid, int r, int c){
        vector<int> nums(10,0);
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int num = grid[i+r][j+c];
                if(num<1 || num>9 || nums[num]) return false;
                else nums[num]++; 
            }
        }

        int summ = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i=1;i<3;i++){
            if(summ != grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2]) return false;
        }
        for(int i=0;i<3;i++){
            if(summ != grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i]) return false;
        }
        if(summ != grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]) return false;
        if(summ != grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]) return false;
        return true;   
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0 , r = grid.size(), c = grid[0].size();
        if(r<3||c<3) return 0;
        for(int i=0;i<r-2;i++) {
            for(int j=0;j<c-2;j++) {
                if(isvalid(grid,i,j)) count++;
            }
        }
        return count;
    }
};