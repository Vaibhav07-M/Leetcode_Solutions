class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mapp;
        for(int i=0;i<n;i++) {
            mapp[nums[i]]++;
            if(mapp[nums[i]]>1) return nums[i];
        }
        return -1;
    }
};

// Alternative optimized solution
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return x;
            seen.insert(x);
        }
        return -1;
    }
};
