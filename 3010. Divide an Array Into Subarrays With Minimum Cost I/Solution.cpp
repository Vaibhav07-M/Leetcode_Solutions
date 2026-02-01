class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(int i=1;i<nums.size();i++) {
            if(nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }

        return first + smallest + secondSmallest;
    }
};
