class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;

        for (auto &q : queries) {
            mx = max(mx, q[1]);
        }

        set<int> pos;
        pos.insert(0);
        pos.insert(mx + 1);

        vector<int> seg(4 * (mx + 5), 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int idx, int val) -> void {
            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (idx <= mid)
                self(self, node * 2, l, mid, idx, val);
            else
                self(self, node * 2 + 1, mid + 1, r, idx, val);

            seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
        };

        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> int {
            if (ql > r || qr < l) return 0;

            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) >> 1;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        for (auto &q : queries) {
            if (q[0] == 1)
                pos.insert(q[1]);
        }

        vector<int> all(pos.begin(), pos.end());

        for (int i = 1; i < all.size(); i++) {
            update(update, 1, 0, mx + 1,
                   all[i], all[i] - all[i - 1]);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            auto &q = queries[i];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto it = pos.upper_bound(x);

                int rightObs = *it;
                --it;

                int leftObs = *it;

                int best = query(
                    query,
                    1,
                    0,
                    mx + 1,
                    0,
                    leftObs
                );

                best = max(best, x - leftObs);

                ans.push_back(best >= sz);

            } else {

                int x = q[1];

                auto it = pos.find(x);

                auto prv = prev(it);
                auto nxt = next(it);

                update(update, 1, 0, mx + 1,
                       *nxt,
                       *nxt - *prv);

                pos.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};