class Solution {
public:
    long long solve(vector<int>& Astart,
                    vector<int>& Adur,
                    vector<int>& Bstart,
                    vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<int,int>> rides;

        for(int i = 0; i < m; i++) {
            rides.push_back({Bstart[i], Bdur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);

        for(int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        vector<long long> prefMinDur(m);
        prefMinDur[0] = rides[0].second;

        for(int i = 1; i < m; i++) {
            prefMinDur[i] =
                min(prefMinDur[i - 1],
                    (long long)rides[i].second);
        }

        vector<long long> suffMinStartDur(m);

        suffMinStartDur[m - 1] =
            (long long)rides[m - 1].first +
            rides[m - 1].second;

        for(int i = m - 2; i >= 0; i--) {
            suffMinStartDur[i] =
                min(suffMinStartDur[i + 1],
                    (long long)rides[i].first +
                    rides[i].second);
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i < Astart.size(); i++) {

            long long T =
                (long long)Astart[i] + Adur[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            T)
                - starts.begin();

            if(pos > 0) {
                ans = min(ans,
                          T + prefMinDur[pos - 1]);
            }

            if(pos < m) {
                ans = min(ans,
                          suffMinStartDur[pos]);
            }
        }

        return ans;
    }

    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        ans = min(ans,
                  solve(landStartTime,
                        landDuration,
                        waterStartTime,
                        waterDuration));

        ans = min(ans,
                  solve(waterStartTime,
                        waterDuration,
                        landStartTime,
                        landDuration));

        return ans;
    }
};