class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool isPalindrome(string &s, int idx, int i){
        if(idx >= i)    return true;

        if(s[idx] == s[i] && isPalindrome(s, idx+1, i-1))
            return true;
        return false;
    }
    void solve(string &s, vector<string> &cur, int idx){
        if(idx == n){
            ans.push_back(cur);
            return;
        }
        for(int i=idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                cur.push_back(s.substr(idx, i - idx + 1));
                solve(s, cur, i+1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        n = s.size();
        solve(s, cur, 0);
        return ans;
    }
};