class Solution {
public:

    vector<string> answer;

    void backtrack(string current, int open, int close, int n) {

        // We have used all brackets
        if (current.size() == 2 * n) {
            answer.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // Add closing bracket
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {

        backtrack("", 0, 0, n);

        return answer;
    }
};
