class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int buy, int i) {
        if (i >= n)
            return 0;

        if (dp[buy][i] != -1)
            return dp[buy][i];
        // condition's if we "CAN" buy or sell and inside them conditions if we
        // "WANT" to
        //  buy or sell

        // buying
        if (!buy) {
            return dp[buy][i] = max(solve(prices, 1, i + 1) - prices[i],
                                    solve(prices, 0, i + 1));
        } // selling
        else {
            return dp[buy][i] = max(solve(prices, 0, i + 2) + prices[i],
                                    solve(prices, 1, i + 1));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        dp.resize(2, vector<int>(n, -1));
        return solve(prices, 0, 0);
    }
};