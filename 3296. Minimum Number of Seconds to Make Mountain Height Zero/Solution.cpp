class Solution {
public:
    bool can(long long T, int h, vector<int>& wt) {
        long long reduced = 0;

        for(long long t : wt) {
            long long val = (2*T)/t;
            long long x = (sqrt(1 + 4*val) - 1) / 2;

            reduced += x;
            if(reduced >= h) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long lo = 0, hi = 1e18;
        long long ans = hi;

        while(lo <= hi) {
            long long mid = (lo + hi) / 2;

            if(can(mid, mountainHeight, workerTimes)) {
                ans = mid;
                hi = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};