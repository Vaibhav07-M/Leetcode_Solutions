class Solution {
public:
    int maximizeSquareArea(int m,int n,vector<int>& hFences,vector<int>& vFences) {
        const long long MOD=1000000007;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<long long> horizontalDistances;

        for(int i=0;i<hFences.size();i++) {
            for(int j=i+1;j<hFences.size();j++) {
                horizontalDistances.insert(hFences[j]-hFences[i]);
            }
        }

        long long bestSide=0;

        for(int i=0;i<vFences.size();i++) {
            for(int j=i+1;j<vFences.size();j++) {
                long long dist=vFences[j]-vFences[i];
                if(horizontalDistances.count(dist)) {
                    bestSide=max(bestSide,dist);
                }
            }
        }

        if(bestSide==0) {
            return -1;
        }

        return (bestSide*bestSide)%MOD;
    }
};
