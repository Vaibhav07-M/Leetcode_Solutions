class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Land -> Water
                int landFinish =
                    landStartTime[i] + landDuration[i];

                int waterBegin =
                    max(landFinish, waterStartTime[j]);

                ans = min(
                    ans,
                    waterBegin + waterDuration[j]
                );

                // Water -> Land
                int waterFinish =
                    waterStartTime[j] + waterDuration[j];

                int landBegin =
                    max(waterFinish, landStartTime[i]);

                ans = min(
                    ans,
                    landBegin + landDuration[i]
                );
            }
        }

        return ans;
    }
};