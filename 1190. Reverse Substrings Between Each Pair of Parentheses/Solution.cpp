class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> st;

        for (char c : s) {

            // Closing bracket
            if (c == ')') {

                string temp = "";

                // Get everything inside the parentheses
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // temp is already reversed
                // because we removed characters from the stack
                for (char ch : temp) {
                    st.push(ch);
                }
            }

            else {
                // Normal character or '('
                st.push(c);
            }
        }

        // Build final answer
        string answer = "";

        while (!st.empty()) {
            answer += st.top();
            st.pop();
        }

        // Stack gives reverse order,
        // so reverse it back
        reverse(answer.begin(), answer.end());

        return answer;
    }
};
