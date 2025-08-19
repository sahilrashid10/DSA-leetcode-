class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0 || n == 1)
            return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        string comb = s +"*"+ rev;
        // why star , try test case aaa

        int m = comb.size();
        vector<int> lps(m, 0);
        int i = 1;
        int len = 0;
        lps[0] = 0;

        while (i < m) {
            if (comb[i] == comb[len]) {
                lps[i] = len + 1;
                len++;
                i++;
            } else {
                if (len > 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return rev.substr(0, n-len) + s;
    }
};

// n^2 time
//  class Solution {
//  public:
//      int n;
//      string shortestPalindrome(string s) {

//         n = s.size();
//         if(n==1 || n==0) return s;

//         int i=0, j = n-1, prev = n-1;
//         while(j>=0){
//             if(s[i] == s[j]){
//                 i++;
//                 j--;
//             }else{
//                 i=0;
//                 j = prev  - 1;
//                 prev = j;
//             }
//         }
//         string sub = s.substr(i);
//         reverse(sub.begin(), sub.end());
//         return sub + s;
//     }
// };

// n^2 time n^2 space, for-->n and inside ->(n-0, n-1, n-2...1) -- substr time
// and space class Solution { public:
//     int n;
//     string shortestPalindrome(string s) {
//         n = s.size();

//         string rev = s;
//         reverse(rev.begin(), rev.end());
//         // a  b  c  c      c  c  b  a
//         // s     ei           si    e

//         for(int i=0; i<n; i++){
//             if(s.substr(0, n-i) == rev.substr(i)){
//                 return rev.substr(0, i)+s;
//             }
//         }
//         return "";
//     }
// };