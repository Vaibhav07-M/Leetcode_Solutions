
class Solution {
public:
    bool canSort(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = -1;

        for (int start = 0; start < n; start += k) {
            int mn = INT_MAX, mx = INT_MIN;
            int descents = 0;

            for (int j = 0; j < k; j++) {
                int curr = nums[start + j];
                int next = nums[start + (j + 1) % k];

                if (curr > next)
                    descents++;

                mn = min(mn, curr);
                mx = max(mx, curr);
            }

            if (descents > 1)
                return false;

            if (start > 0 && prevMax > mn)
                return false;

            prevMax = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k * k <= n; k++) {
            if (n % k != 0)
                continue;

            if (canSort(nums, k))
                ans += k;

            int other = n / k;

            if (other != k && canSort(nums, other))
                ans += other;
        }

        return ans;
    }
};
