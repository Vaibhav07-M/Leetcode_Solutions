class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long absoluteSum = 0;
        int negativeElements = 0;
        int minimumAbsoluteValue = INT_MAX;

        for (const auto& currentRow : matrix) {
            for (int cellValue : currentRow) {
                if (cellValue < 0)
                    negativeElements++;

                absoluteSum += llabs(cellValue);
                minimumAbsoluteValue = min(minimumAbsoluteValue, abs(cellValue));
            }
        } 

        if (negativeElements % 2 == 1) {
            absoluteSum -= 2LL * minimumAbsoluteValue;
        }

        return absoluteSum;
    }
};
