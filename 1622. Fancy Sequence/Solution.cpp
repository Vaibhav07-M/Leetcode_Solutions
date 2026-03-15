class Fancy {
public:
    const long long MOD = 1e9+7;

    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long x){
        long long res = 1;
        long long power = MOD-2;

        while(power){
            if(power & 1) res = (res*x)%MOD;
            x = (x*x)%MOD;
            power >>= 1;
        }

        return res;
    }

    Fancy() {}

    void append(int val) {
        long long inv = modInverse(mul);
        long long x = ((val - add + MOD) % MOD * inv) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;

        long long val = (arr[idx]*mul + add) % MOD;
        return val;
    }
};