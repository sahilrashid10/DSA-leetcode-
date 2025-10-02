class Solution {
public:
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        vector<int> dp(r+1, 1);

        for(int i=1; i<n; i++){
            //for odd length in am keeping the sequence increasing
            // by starting with keeping 1 length as increasing
            vector<int> newDp(r+1, 0);
            if(i%2 != 0){
                int prev = 0;
                for(int j=l; j<=r; j++){
                    newDp[j] = prev;
                    prev = (prev + dp[j]) % mod;
                }
            }else{
                int nex = 0;
                for(int j=r; j>=l; j--){
                    newDp[j] = nex;
                    nex = (dp[j] + nex) % mod;
                }
            }
            dp = newDp;
        }
        int ans = 0;
        for(int i=1; i<dp.size(); i++){
            int num = dp[i];
            ans = (ans + num) % mod;
        }
        return (2*ans) % mod;
    }
};

// class Solution {
// public:
//     // memo[state] = number of valid arrays from this state
//     // state: (pos, last, secondLast)
//     map<tuple<int,int,int>, int> memo;
    // int mod = 1e9 + 7;
//     int solve(int n, int l, int r, int pos, int last, int secondLast) {
//         if (pos == n) return 1;  // built an array of length n

//         auto key = make_tuple(pos, last, secondLast);
//         if (memo.count(key)) return memo[key];

//         int ways = 0;

//         for (int num = l; num <= r; num++) {
//             // check constraints
//             if (pos >= 2) {
//                 // need zigzag: last two go up and current goes down, or last two go down and current goes up
//                 if ((secondLast < last && last < num) || (secondLast > last && last > num))
//                     continue;
//             }
//             if (pos >= 1) {
//                 if (num == last) continue; // no equal adjacent
//             }

//             ways += solve(n, l, r, pos + 1, num, last) % mod;
//         }

//         return memo[key] = ways % mod;
//     }

//     int zigZagArrays(int n, int l, int r) {
//         memo.clear();
//         return solve(n, l, r, 0, -1, -1); // start with dummy last values
//     }
// };
