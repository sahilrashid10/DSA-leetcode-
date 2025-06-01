class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for (int c1 = max(0, n - 2 * limit); c1 <= min(limit, n); c1++){
            int c2s = max(0, n - c1 - limit);
            int c2e = min(limit, n - c1);
            int range = (c2e - c2s + 1);
            ans += range;
        }
        return ans;
    }
};