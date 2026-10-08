class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer;
        int depth = 0;

        for (char c : s) {

            if (c == '(') {
                if (depth > 0)
                    answer += '(';

                depth++;
            }
            else {
                depth--;

                if (depth > 0)
                    answer += ')';
            }
        }

        return answer;
    }
};
