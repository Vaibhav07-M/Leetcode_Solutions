class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Possible prime counts of set bits up to 20 bits
        unordered_set<int> primeCount = {2, 3, 5, 7, 11, 13, 17, 19};

        int ans = 0;
        for(int x=left;x<=right;x++) {
            int cnt = __builtin_popcount(x);  // counts number of 1 bits
            if(primeCount.count(cnt)) {
                ans++;
            }
        }
        return ans;
    }
};