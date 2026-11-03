class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Find the maximum element
        int maximum = *max_element(nums.begin(), nums.end());

        int moves = 0;

        // Calculate the required moves
        for (int i = 0; i < nums.size(); i++) {
            moves += maximum - nums[i];
        }

        return moves;
    }
};
