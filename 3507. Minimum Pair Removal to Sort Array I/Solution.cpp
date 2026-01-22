class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(true) {
            bool sorted = true;

            for(int i=1;i<nums.size();i++) {
                if(nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            if(sorted) {
                break;
            }

            int minSum = INT_MAX;
            int index = 0;

            for(int i=0;i+1<nums.size();i++) {
                int sum = nums[i] + nums[i + 1];
                if(sum<minSum) {
                    minSum = sum;
                    index = i;
                }
            }

            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);

            operations++;
        }

        return operations;
    }
};
