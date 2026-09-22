class Solution {
public:

    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;

        // Product of the complete segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Prefixes that contain all of left
        // and then continue into right
        for (int r = 0; r < k; r++) {
            int newRemainder = (left.prod * r) % k;

            res.cnt[newRemainder] += right.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {
            int rem = value % k;

            tree[node] = Node();

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Complete segment is inside query
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely in left
        if (qr <= mid) {
            return query(
                node * 2,
                l,
                mid,
                ql,
                qr
            );
        }

        // Completely in right
        if (ql > mid) {
            return query(
                node * 2 + 1,
                mid + 1,
                r,
                ql,
                qr
            );
        }

        // Split between left and right
        Node left = query(
            node * 2,
            l,
            mid,
            ql,
            qr
        );

        Node right = query(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr
        );

        return mergeNodes(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        // Build segment tree
        build(nums, 1, 0, n - 1);

        vector<int> answer;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Step 1: Update nums[index]
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // Step 2: Query [start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            // Step 3: Number of prefixes
            // having product remainder x
            answer.push_back(res.cnt[x]);
        }

        return answer;
    }
};
