class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = n + 1; // Initialize with a value larger than any possible distance
        unordered_map<int, int> last_mirror_pos;

        auto get_reverse = [](int x) {
            int rev = 0;
            while (x > 0) {
                rev = rev * 10 + (x % 10);
                x /= 10;
            }
            return rev;
        };

        for (int i = 0; i < n; ++i) {
            // If the current number matches a previously recorded reverse(nums[j])
            if (last_mirror_pos.count(nums[i])) {
                min_dist = min(min_dist, i - last_mirror_pos[nums[i]]);
            }
            
            // Store the current number's reverse and its index i
            // This allows future nums[j] to find its mirror at index i
            last_mirror_pos[get_reverse(nums[i])] = i;
        }

        return (min_dist > n) ? -1 : min_dist;
    }
};