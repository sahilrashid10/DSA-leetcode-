/* Approach: Recursion + Memo
At each day, try all 3 possibilities:
1. Do noting
2. Buy 
3. Sell
Maintain a status variable to check current status
0- no transaction ongoing, 1- normal transaction ongoing, 2- short transaction ongoing
Memoize using dp
dp[i][status][rem_transactions] - maximum profit that can be earned from day i, given the current status
and remaining transaction count as rem_transactions.
Handle cases like:
a) if transaction is already ongoing then we can close it or do nothing
b) On last day, if any transaction is ongoing, we need to close it.
c) if no transactions left, we can not earn more profit.
Time: O(n * 3 * k)
Space: O(n * 3 * k)
*/

class Solution {
public:
    // status: 0 - no operation, 1 - bought, 2 - short
    long long f(int i, int status, int rem_transactions, vector<int>& prices,
                     vector<vector<vector<long long>>>& dp) {
        // base cases: 
        // 1. no transactions left
        if(rem_transactions == 0)
            return 0;
        // 2. Last day: close all ongoing transactions
        if(i == prices.size() - 1) {
            if(status == 0) return 0;           // no operation -> do nothing
            if(status == 1) return prices[i];   // sell if previously bought
            return -prices[i];                  // buy if previously sold
        }

        // Already calculated
        if(dp[i][status][rem_transactions] != INT_MIN)
            return dp[i][status][rem_transactions];
    
        // Try all possibilities
        long long ans = INT_MIN;
        // 1. Do nothing
        ans = max(ans, f(i + 1, status, rem_transactions, prices, dp));
        if(status == 0){    // previously nothing done
            // buy
            ans = max(ans, -prices[i] + f(i + 1, 1, rem_transactions, prices, dp));
            // sell
            ans = max(ans, prices[i] + f(i+1, 2, rem_transactions, prices, dp));

        } else if (status == 1){   // previously bought
            // sell 
            ans = max(ans, prices[i] + f(i + 1, 0, rem_transactions-1, prices, dp));
        } else {        // previously sold
            // buy
            ans = max(ans, -prices[i] + f(i + 1, 0, rem_transactions-1, prices, dp));
        }
        return dp[i][status][rem_transactions] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(k+1, INT_MIN)));
        return f(0, 0, k, prices, dp);
    }
};