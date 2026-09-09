class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        for (long long power = 1000; power <= n; power *= 1000) {
            ans += n - power + 1;
        }
        
        return ans;
    }
};
