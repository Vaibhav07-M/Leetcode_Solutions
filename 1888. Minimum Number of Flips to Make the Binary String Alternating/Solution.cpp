class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;

        int alt1 = 0, alt2 = 0;
        int res = INT_MAX;

        for(int i=0;i<s2.size();i++) {

            if(s2[i] != (i % 2 ? '1' : '0')) alt1++;
            if(s2[i] != (i % 2 ? '0' : '1')) alt2++;

            if(i >= n) {
                if(s2[i-n] != ((i-n) % 2 ? '1' : '0')) alt1--;
                if(s2[i-n] != ((i-n) % 2 ? '0' : '1')) alt2--;
            }

            if(i >= n-1) {
                res = min(res, min(alt1, alt2));
            }
        }

        return res;
    }
};