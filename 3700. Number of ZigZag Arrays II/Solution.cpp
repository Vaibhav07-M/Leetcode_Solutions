class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();

        Matrix C(sz, vector<long long>(sz, 0));

        for(int i = 0; i < sz; i++) {
            for(int k = 0; k < sz; k++) {

                if(A[i][k] == 0) continue;

                for(int j = 0; j < sz; j++) {

                    if(B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] +
                        A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {

        int sz = base.size();

        Matrix res(sz, vector<long long>(sz, 0));

        for(int i = 0; i < sz; i++)
            res[i][i] = 1;

        while(exp) {

            if(exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);

            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        for(int x = 0; x < m; x++) {

            for(int y = 0; y < x; y++) {
                T[x][m + y] = 1;
            }

            for(int y = x + 1; y < m; y++) {
                T[m + x][y] = 1;
            }
        }

        vector<long long> base(S);

        for(int x = 0; x < m; x++) {
            base[x] = x;
            base[m + x] = m - 1 - x;
        }

        if(n == 2) {
            long long ans = 0;

            for(long long v : base)
                ans = (ans + v) % MOD;

            return ans;
        }

        Matrix P = power(T, n - 2);

        vector<long long> state(S, 0);

        for(int i = 0; i < S; i++) {
            for(int j = 0; j < S; j++) {

                state[i] =
                    (state[i] +
                     P[i][j] * base[j]) % MOD;
            }
        }

        long long ans = 0;

        for(long long v : state)
            ans = (ans + v) % MOD;

        return (int)ans;
    }
};