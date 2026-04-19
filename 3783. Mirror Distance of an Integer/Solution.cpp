class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0;
        int orignal = n;
        while(n!=0) {
            int digit = n%10;
            if(reverse>INT_MAX/10|| (reverse == INT_MAX/10 && digit>7)) return 0;
            if (reverse < INT_MIN/10 || (reverse == INT_MIN/10 && digit < -8)) return 0;
            reverse = (reverse * 10) + digit;
            n /= 10;
        }
        return abs(reverse-orignal);
    }
};