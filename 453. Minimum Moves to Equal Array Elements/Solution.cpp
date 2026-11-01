class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Find the minimum element
        int minimum = *min_element(nums.begin(), nums.end());

        int moves = 0;

        // Calculate total difference
        for (int i = 0; i < nums.size(); i++) {
            moves += nums[i] - minimum;
        }

        return moves;
    }
};
