class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int p = prices.size();
        int s = strategy.size();

        vector<long long> originalSum(s, 0);
        vector<long long> windowStrategy(s, 0);
        long long baseProfit = 0;
        long long sum = 0;

        for(int i=0; i<p; i++){
            baseProfit = baseProfit + prices[i]*strategy[i]; 
            originalSum[i] = baseProfit;
            sum += prices[i];
            windowStrategy[i] = sum;
        }

        long long ans = baseProfit;

        for(int i=k-1; i<p; i++){
            long long leftHalfNoStrategy = 0,
            rightHalfNoStrategy = 0,
            windowProfit = 0;

            if(i-k >= 0)
                leftHalfNoStrategy = originalSum[i-k];
            rightHalfNoStrategy = originalSum[p-1] - originalSum[i];

            windowProfit = windowStrategy[i] - windowStrategy[i-(k/2)];
            ans = max(ans, (leftHalfNoStrategy + windowProfit + rightHalfNoStrategy));
        }
        return ans;
    }
};

//T- O(p-k+1)*k = p^2 = n^2
// class Solution {
// public:
//     long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
//         int p = prices.size();
//         int s = strategy.size();
//         long long mp=0, ans;
//         for(int i = 0; i<p; i++)
//             mp = mp + prices[i] * strategy[i];
        
//         ans = mp;
        
//         for(int i=0; i<=p-k; i++){
//             long long profit = mp;
//             int half = 0;
//             for(int j = i; j<k+i; j++){
//                 if(half < k/2)
//                     profit = profit - (prices[j]*strategy[j]);
                // else{
                //     profit = profit - (prices[j]*strategy[j]);
                //     profit += prices[j];
                // }
//                 half++;
//             }
//             ans = max(ans, profit);
//         }
//         return ans;
//     }
// };