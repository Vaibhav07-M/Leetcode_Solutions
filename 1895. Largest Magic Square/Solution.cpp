class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>> rowSum(rows,vector<int>(cols+1,0));
        vector<vector<int>> colSum(rows+1,vector<int>(cols,0));
        vector<vector<int>> diag1(rows+1,vector<int>(cols+1,0));
        vector<vector<int>> diag2(rows+1,vector<int>(cols+2,0));

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                rowSum[i][j+1]=rowSum[i][j]+grid[i][j];
                colSum[i+1][j]=colSum[i][j]+grid[i][j];
                diag1[i+1][j+1]=diag1[i][j]+grid[i][j];
                diag2[i+1][j]=diag2[i][j+1]+grid[i][j];
            }
        }

        int maxSize=min(rows,cols);

        for(int size=maxSize;size>=2;size--) {
            for(int r=0;r+size<=rows;r++) {
                for(int c=0;c+size<=cols;c++) {

                    int target=rowSum[r][c+size]-rowSum[r][c];

                    bool valid=true;

                    for(int i=0;i<size;i++) {
                        int row=rowSum[r+i][c+size]-rowSum[r+i][c];
                        int col=colSum[r+size][c+i]-colSum[r][c+i];

                        if(row!=target||col!=target) {
                            valid=false;
                            break;
                        }
                    }

                    if(!valid) {
                        continue;
                    }

                    int d1=diag1[r+size][c+size]-diag1[r][c];
                    int d2=diag2[r+size][c]-diag2[r][c+size];

                    if(d1==target&&d2==target) {
                        return size;
                    }
                }
            }
        }

        return 1;
    }
};
