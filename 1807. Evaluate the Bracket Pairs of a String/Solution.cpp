class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        // Store key -> value
        for (auto& item : knowledge) {
            mp[item[0]] = item[1];
        }

        string answer;

        for (int i = 0; i < s.size(); i++) {

            // Normal character
            if (s[i] != '(') {
                answer += s[i];
            }

            // Bracket pair
            else {
                int j = i + 1;

                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    answer += mp[key];
                }
                else {
                    answer += "?";
                }

                // Move past ')'
                i = j;
            }
        }

        return answer;
    }
};
