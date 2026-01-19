class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat,int threshold) {
        int rows=mat.size();
        int cols=mat[0].size();

        vector<vector<int>> prefix(rows+1,vector<int>(cols+1,0));

        for(int i=1;i<=rows;i++) {
            for(int j=1;j<=cols;j++) {
                prefix[i][j]=mat[i-1][j-1]
                            +prefix[i-1][j]
                            +prefix[i][j-1]
                            -prefix[i-1][j-1];
            }
        }

        int left=0;
        int right=min(rows,cols);
        int answer=0;

        while(left<=right) {
            int mid=(left+right)/2;
            bool found=false;

            for(int i=0;i+mid<=rows;i++) {
                for(int j=0;j+mid<=cols;j++) {
                    int sum=prefix[i+mid][j+mid]
                           -prefix[i][j+mid]
                           -prefix[i+mid][j]
                           +prefix[i][j];

                    if(sum<=threshold) {
                        found=true;
                        break;
                    }
                }
                if(found) {
                    break;
                }
            }

            if(found) {
                answer=mid;
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }

        return answer;
    }
};
