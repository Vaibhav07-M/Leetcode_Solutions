class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int answer = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // If the next character is ')',
                // we have a complete '))' pair
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert one ')' to complete the pair
                    answer++;
                }

                // Match this '))' with an opening '('
                if (open > 0) {
                    open--;
                }
                else {
                    // Insert a missing '('
                    answer++;
                }
            }
        }

        // Each remaining '(' needs two ')'
        answer += open * 2;

        return answer;
    }
};
