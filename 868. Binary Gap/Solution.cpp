class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;   // position of previous 1 bit
        int pos = 0;       // current bit position
        int ans = 0;

        while(n>0) {
            if(n & 1) {   // if current bit is 1
                if(lastPos != -1) {
                    ans = max(ans, pos - lastPos);
                }
                lastPos = pos;
            }
            n >>= 1;
            pos++;
        }
        return ans;
    }
};