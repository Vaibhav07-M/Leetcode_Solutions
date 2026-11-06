class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        // Store query time and original index
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        // Sort queries by time
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> answer(q);

        // Frequency of requests for each server
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int activeServers = 0;

        // Process queries in sorted order
        for (auto [time, index] : sortedQueries) {

            int start = time - x;

            // Add logs with time <= query time
            while (right < logs.size() &&
                   logs[right][1] <= time) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    activeServers++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs with time < query - x
            while (left < right &&
                   logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Servers with zero requests
            answer[index] = n - activeServers;
        }

        return answer;
    }
};
