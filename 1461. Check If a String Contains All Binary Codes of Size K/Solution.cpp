class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k) return false;

        int need = 1 << k;               // total possible codes = 2^k
        vector<bool> seen(need, false);

        int mask = 0;
        int allOnes = need - 1;          // mask to keep only last k bits
        int count = 0;

        for(int i = 0; i < n; i++) {
            // build rolling mask
            mask = ((mask << 1) & allOnes) | (s[i] - '0');

            // start checking only after first k-1 chars
            if(i >= k - 1) {
                if(!seen[mask]) {
                    seen[mask] = true;
                    count++;
                    if(count == need) return true;  // early exit
                }
            }
        }
        return false;
    }
};