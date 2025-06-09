class Solution {
public:
    long long getCount(long long cur, long long nex, int n) {
        long long count = 0;
        while (cur <= n) {
            count += min((long long)n + 1, nex) - cur;
            cur *= 10;
            nex *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        long long cur = 1;
        k--;  // because 1 is the first number

        while (k > 0) {
            long long count = getCount(cur, cur + 1, n);
            if (count <= k) {
                k -= count;
                cur++;
            } else {
                cur *= 10;
                k--;
            }
        }
        return (int)cur;
    }
};





// class Solution {
// public: 

//     void solve(long long num, long long n, int &k, long long &ans){

//         if(k == 0){
//             ans = num;
//             return;
//         }

//         for(int i=0; i<=9 && ans == -1; i++){
//             long long newNum = num*10 + i;
//             if(newNum > n)
//                 return;
//             k--;
//             solve(newNum, n, k, ans);
//         }
//     }
//     int findKthNumber(int n, int k) {
        
//         long long ans = -1;
//         if(n<=9)
//             return k;
//         for(long long i=1; i<=9 && ans == -1; i++){
//             k--;
//             solve(i, n, k, ans);
//         }
//         return int(ans);  
//     }
// };