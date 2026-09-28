class Solution {
public:
    int maxDepth(string s) {

        int depth = 0;
        int answer = 0;

        for (char c : s) {

            if (c == '(') {
                depth++;

                answer = max(answer, depth);
            }

            else if (c == ')') {
                depth--;
            }
        }

        return answer;
    }
};
