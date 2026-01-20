class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i=0;i<nums.size();i++) {
            int value=nums[i];

            // Power of two → impossible
            if((value&(value-1))==0) {
                ans[i]=-1;
                continue;
            }

            int chosenBit=-1;

            // Find the highest valid k
            for(int k=31;k>=0;k--) {
                if(((value>>k)&1)==1) {
                    int mask=(1<<k)-1;
                    if((value&mask)==mask) {
                        chosenBit=k;
                        break;
                    }
                }
            }

            ans[i]=value^(1<<chosenBit);
        }

        return ans;
    }
};
