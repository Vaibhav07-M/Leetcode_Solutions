// Optimized DP solution with memoization
class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>> t;
    string avail[12] = {"RGY","RYG","RYR","RGR","GYR","GRY","GYG","GRG","YGR","YRG","YGY","YRY"};

    int solver(int n, int prev) {
        if(n==0) return 1;

        if(t[n][prev] != -1) return t[n][prev];

        int result = 0;
        string last = avail[prev];

        for(int i=0;i<12;i++) {

            if(i == prev) continue;

            string current = avail[i];
            bool change = false;
            
            for(int col=0;col<3;col++) {
            
                if(current[col] == last[col]) {
                    change = true;
                    break;
                }
            }
            
            if(!change) {
                result = (result + solver(n-1,i)) % M;
            }
        }
        return t[n][prev] = result;
    } 
    int numOfWays(int n) {
        t.resize(n,vector<int>(12,-1));
        int result = 0;
        
        for(int i=0;i<12;i++) {
            result = (result + solver(n-1,i)) % M;
        }
        return result;
    }
};
// Optimized DP solution with space optimization
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long twoColorWays = 6;
        long long threeColorWays = 6;

        for (int row = 2; row <= n; row++) {
            long long nextTwoColorWays = (3 * twoColorWays + 2 * threeColorWays) % MOD;

            long long nextThreeColorWays = (2 * twoColorWays + 2 * threeColorWays) % MOD;

            twoColorWays = nextTwoColorWays;
            threeColorWays = nextThreeColorWays;
        }

        return (twoColorWays + threeColorWays) % MOD;
    }
};
