class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Sort the array
        sort(nums.begin(), nums.end());

        // Find the median
        int median = nums[nums.size() / 2];

        int moves = 0;

        // Calculate total moves
        for (int i = 0; i < nums.size(); i++) {
            moves += abs(nums[i] - median);
        }

        return moves;
    }
};
