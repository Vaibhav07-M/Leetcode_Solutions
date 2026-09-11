class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> numbers;

        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {

                    // Cannot use the same copy twice
                    if (i == j || i == k || j == k)
                        continue;

                    // First digit cannot be 0
                    if (digits[i] == 0)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    numbers.insert(num);
                }
            }
        }

        return numbers.size();
    }
};
