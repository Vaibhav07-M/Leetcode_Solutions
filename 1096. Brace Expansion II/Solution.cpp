class Solution {
public:

    string s;
    int pos;

    set<string> parseExpression() {

        set<string> result = parseTerm();

        while (pos < s.size() && s[pos] == ',') {
            pos++;

            set<string> next = parseTerm();

            // Union
            for (string word : next) {
                result.insert(word);
            }
        }

        return result;
    }

    set<string> parseTerm() {

        set<string> result;
        result.insert("");

        while (pos < s.size() &&
               s[pos] != '}' &&
               s[pos] != ',') {

            set<string> next;

            if (s[pos] == '{') {

                pos++; // skip '{'

                next = parseExpression();

                pos++; // skip '}'

            }
            else {

                // Single letter
                next.insert(string(1, s[pos]));
                pos++;
            }

            // Concatenation
            set<string> combined;

            for (string a : result) {
                for (string b : next) {
                    combined.insert(a + b);
                }
            }

            result = combined;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};
