class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            // Closing brackets
            else {

                // No opening bracket to match
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Check matching pair
                if (c == ')' && top != '(')
                    return false;

                if (c == ']' && top != '[')
                    return false;

                if (c == '}' && top != '{')
                    return false;
            }
        }

        // All brackets must be matched
        return st.empty();
    }
};
