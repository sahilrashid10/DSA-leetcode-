class Solution {
public:
    static const int MOD = 1e9 + 7;

    void precomputeFactorials(vector<long long>& fact, vector<long long>& invFact, int maxN) {
        fact[0] = 1;
        for (int i = 1; i <= maxN; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[maxN] = modularInverse(fact[maxN], MOD);
        for (int i = maxN - 1; i >= 0; --i) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

    long long modularInverse(long long a, int mod) {
        return power(a, mod - 2, mod);
    }

    long long power(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }

    long long combination(int n, int r, vector<long long>& fact, vector<long long>& invFact) {
        if (r > n || r < 0) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> fact(n + 1), invFact(n + 1);
        precomputeFactorials(fact, invFact, n);

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                long long term = nums[i] * (combination(i, j, fact, invFact) + combination(n - i - 1, j, fact, invFact)) % MOD;
                ans = (ans + term) % MOD;
            }
        }
        return ans;
    }
};
