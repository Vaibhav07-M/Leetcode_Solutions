class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i=0;i<nums.size();i++) {
            int value = nums[i];

            // Power of two → impossible
            if((value & (value-1)) == 0) {
                ans[i] = -1;
                continue;
            }

            int chosenBit = -1;

            // Find highest valid bit to turn off
            for(int k=31;k>=0;k--) {
                if(((value>>k) & 1) == 1) {
                    int lowerMask = (1 << k) - 1;
                    if((value & lowerMask) == lowerMask) {
                        chosenBit = k;
                        break;
                    }
                }
            }

            ans[i] = value ^ (1 << chosenBit);
        }

        return ans;
    }
};
