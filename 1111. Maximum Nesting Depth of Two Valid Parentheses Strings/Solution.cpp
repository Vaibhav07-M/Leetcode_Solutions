class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> answer;

        int depth = 0;

        for (char c : seq) {

            if (c == '(') {

                // Assign based on current depth
                answer.push_back(depth % 2);

                depth++;
            }

            else {

                depth--;

                // Assign based on new depth
                answer.push_back(depth % 2);
            }
        }

        return answer;
    }
};
