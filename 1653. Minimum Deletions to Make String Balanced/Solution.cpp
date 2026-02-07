class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0;
        int deletions = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'b') {
                countB++;
            }
            else {
                deletions = min(deletions + 1, countB);
            }
        }

        return deletions;
    }
};
