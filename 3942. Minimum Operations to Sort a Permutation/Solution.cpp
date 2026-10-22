
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Already sorted
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }

        if (sorted)
            return 0;

        int c = nums[0];

        // Check ascending cyclic order
        bool ascending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (c + i) % n) {
                ascending = false;
                break;
            }
        }

        if (ascending) {
            int k = (n - c) % n;
            return min(k, n - k + 2);
        }

        // Check descending cyclic order
        bool descending = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (c - i + n) % n) {
                descending = false;
                break;
            }
        }

        if (descending) {
            int d = (c + 1) % n;
            return min(d, n - d) + 1;
        }

        return -1;
    }
};
