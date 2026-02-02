class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long answer = LLONG_MAX;

        multiset<int> small;
        multiset<int> large;
        long long sumSmall = 0;

        auto add = [&](int value) {
            if(small.size() < k - 1) {
                small.insert(value);
                sumSmall += value;
            } 
            else if(!small.empty() && value < *prev(small.end())) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
                small.insert(value);
                sumSmall += value;
            } 
            else {
                large.insert(value);
            }
        };

        auto remove = [&](int value) {
            auto itSmall = small.find(value);
            if(itSmall != small.end()) {
                sumSmall -= value;
                small.erase(itSmall);
                if(!large.empty()) {
                    auto itLarge = large.begin();
                    small.insert(*itLarge);
                    sumSmall += *itLarge;
                    large.erase(itLarge);
                }
            } 
            else {
                large.erase(large.find(value));
            }
        };

        // initial window
        for(int i=1;i<=dist + 1 && i<n;i++) {
            add(nums[i]);
        }

        if(small.size() == k - 1) {
            answer = min(answer, nums[0] + sumSmall);
        }

        // slide window
        for(int i=dist + 2;i<n;i++) {
            remove(nums[i - dist - 1]);
            add(nums[i]);

            if(small.size() == k - 1) {
                answer = min(answer, nums[0] + sumSmall);
            }
        }

        return answer;
    }
};
