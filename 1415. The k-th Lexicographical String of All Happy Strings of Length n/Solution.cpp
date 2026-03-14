class Solution {
public:
    string getHappyString(int n, int k) {
        
        int total = 3 * (1 << (n-1));
        if(k > total) return "";

        string ans = "";
        vector<char> letters = {'a','b','c'};

        char prev = '#';

        for(int i=0;i<n;i++) {

            int remain = n - i - 1;

            for(char c : letters) {

                if(c == prev) continue;

                int cnt = 1 << remain;

                if(k > cnt) {
                    k -= cnt;
                }
                else {
                    ans += c;
                    prev = c;
                    break;
                }
            }
        }

        return ans;
    }
};