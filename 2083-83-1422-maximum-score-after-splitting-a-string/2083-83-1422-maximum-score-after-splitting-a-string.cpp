//  OPTIMAL SOLUTION single pas
class Solution {
public:
    int maxScore(string s) {
        int z = 0, o = 0;
        int score=INT_MIN; 
        int ans = 0;
        for (int i = 0; i < s.size()-1; i++) {
            s[i] == '0' ? z++ : o++;  
            score = max(score, z-o);
        }
        if(s[s.size()-1]=='1')
            o++;

        return score+o;
    }
};
//BETTER SOLUTION
// class Solution {
// public:
//     int maxScore(string s) {
//         int total1s = count(s.begin(), s.end(), '1');
//         int z=0, o=0;
//         int ans = 0;
//         for(int i=0; i<s.size()-1; i++){
//             s[i]=='0'?z++:o++;
//             int r1 = total1s - o;
//             ans = max(ans, z+r1);
//         }

//         return ans;
//     }
// };
//BRUTE FORCE
// class Solution {
// public:
//     int maxScore(string s) {
//         int i=0, n=s.size(), j=1, ans=0;
//         while(j<n){
//             string l = s.substr(i, j-i);
//             string r = s.substr(j, n-j);
//             int lval=0, rval=0;
//             for(int k=0; k<l.size(); k++){
//                 if(l[k]=='0')
//                     lval++;
//             }
//             for(int k=0; k<r.size(); k++){
//                 if(r[k]=='1')
//                     rval++;
//             }
//             ans = max(ans, lval+rval);
//             j++;
//         }
//         return ans;
//     }
// };