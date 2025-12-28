class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // int rows = grid.size();
        // int columns = grid[0].size();
        // int count = 0;
        // int i = rows-1;
        // int j = 0;

        // while(i>=0 && j<columns) {
        //     if(grid[i][j] < 0) {
        //         count += columns -j;
        //         i--;
        //     }
        //     else j++;
        // }
        // return count;
        
        int rows=grid.size();
        int columns=grid[0].size();
        int count =0;
        for(int i=0;i<rows;i++){
            for(int j=columns-1;j>=0;j--){
                 if(grid[i][j]<0)count++;
                 else break;
            }
        }
        return count;
    }
};