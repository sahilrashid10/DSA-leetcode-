/*BOTTOM UP WITH CONSTANT SPACE*/   
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        int a = 1;
        int b = 2;
        int ans = 0;
        for(int i=3; i<=n; i++){
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};

/*BOTTOM UP*/
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> t(n+1, 0);

//         if(n <= 2) return n;

//         t[0] = 0;
//         t[1] = 1;
//         t[2] = 2;
//         for(int i=3; i<=n; i++){
//             t[i] = t[i-1] + t[i-2];
//         }
//         return t[n];
//     }
// };
/*RECURSION + MEMOIZATION*/
// class Solution {
// public:
//     int t[46];

//     int solve(int n){
//         if(n < 0) return 0;
//         if(n == 0){
//             return 1;
//         }
//         if(t[n] != -1) return t[n];

//         int oneStep = solve(n-1);
//         int twoStep = solve(n-2);

//         return t[n] = oneStep + twoStep;
//     }
//     int climbStairs(int n) {
//         memset(t, -1, sizeof(t));
//         int count = solve(n);
//         return count;
//     }
// };
/*RECURSION*/
// class Solution {
// public:
//     void solve(int n, int i, int &count){
//         if(i > n) return;
//         if(i == n){
//             count++;
//             return;
//         }

//         solve(n, i+1, count);
//         solve(n, i+2, count);
//     }
//     int climbStairs(int n) {
//         int count = 0;
//         solve(n, 0, count);
//         return count;
//     }
// };