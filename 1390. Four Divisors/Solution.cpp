class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int finalSum = 0;

        for(int number : nums) {
            int divisorCount = 0;
            int divisorSum = 0;

            for(int candidate = 1; candidate * candidate <= number; candidate++) {
                if(number % candidate == 0) {
                    int pairedDivisor = number / candidate;

                    divisorCount++;
                    divisorSum += candidate;

                    if(pairedDivisor != candidate) {
                        divisorCount++;
                        divisorSum += pairedDivisor;
                    }

                    if(divisorCount > 4) break;
                }
            }

            if(divisorCount == 4)
                finalSum += divisorSum;
        }

        return finalSum;
    }
};
