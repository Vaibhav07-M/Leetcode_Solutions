class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
            }
            else if (c == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> answer;
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();

            while (size--) {
                string current = q.front();
                q.pop();

                if (isValid(current)) {
                    answer.push_back(current);
                    found = true;
                    continue;
                }

                // Generate strings by removing one parenthesis
                for (int i = 0; i < current.size(); i++) {

                    if (current[i] != '(' && current[i] != ')')
                        continue;

                    string next = current.substr(0, i) +
                                  current.substr(i + 1);

                    if (visited.count(next))
                        continue;

                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return answer;
    }
};
