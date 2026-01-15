class Solution {
public:
    int maximizeSquareHoleArea(int n,int m,vector<int>& hBars,vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maxRowGap=1;
        int maxColGap=1;

        int currentGap=1;

        for(int i=1;i<hBars.size();i++) {
            if(hBars[i]==hBars[i-1]+1) {
                currentGap++;
            }
            else {
                currentGap=1;
            }
            maxRowGap=max(maxRowGap,currentGap);
        }

        currentGap=1;

        for(int i=1;i<vBars.size();i++) {
            if(vBars[i]==vBars[i-1]+1) {
                currentGap++;
            }
            else {
                currentGap=1;
            }
            maxColGap=max(maxColGap,currentGap);
        }

        int side=min(maxRowGap+1,maxColGap+1);
        return side*side;
    }
};
