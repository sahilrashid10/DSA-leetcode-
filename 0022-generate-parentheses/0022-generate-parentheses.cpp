/*BRUTE FORCE RECURSION 
T-O(n*2^2n)   S-O(2n) recurion aur auxi space: BOHOT ZADA
*/

// class Solution {
// public:
//     vector<string>ans;
//     string sub;

//     bool valid(){
//         int count=0;
//         for(int i=0; i<sub.size(); i++){
//             if(count < 0) return false;
//             if(sub[i]=='(') count += 1;
//             if(sub[i]==')') count -= 1;
//         }
//         return (count==0)?true:false;
//     }
//     void solve(int n, int i){
//         if( i >= 2*n){
//             if(valid())
//                 ans.push_back(sub);
//             return;
//         }
//         sub += '(';
//         solve(n, i+1);
//         sub.pop_back();
//         sub += ')';
//         solve(n, i+1);
//         sub.pop_back();
//     }
//     vector<string> generateParenthesis(int n) {
//         solve(n, 0);
//         return ans;
//     }
// };

/*BETTER APPROACH:
same as approach 1 but use open, close variables to avoid creating wrong paranthesis
*/
class Solution {
public:
    vector<string>ans;
    string sub;
    void solve(int n, int i, int open, int close){
        if( i >= 2*n){
            ans.push_back(sub);
            return;
        }
        if(open<n){
        sub += '(';
        solve(n, i+1, open+1, close);
        sub.pop_back();
        }
        if(close<open){
        sub += ')';
        solve(n, i+1, open, close+1);
        sub.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, 0);
        return ans;
    }
};