class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int num : nums) {
            squares.push_back(1LL * num * num);
        }

        sort(squares.begin(), squares.end());

        int n = squares.size();
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                answer += squares[n - 1 - i];
            } else {
                answer -= squares[n - 1 - i];
            }
        }

        return answer;
    }
};
