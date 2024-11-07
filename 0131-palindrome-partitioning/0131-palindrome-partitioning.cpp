class Solution {
public:
    vector<vector<string>>ans;
    vector<string>sub;
    bool notPal(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return true;
            i++;
            j--;
        }
        return false;
    }
    void solve(string &s, int i){
        if(i>=s.size()){
            ans.push_back(sub);
            return;
        }
        for(int j=i; j<s.size(); j++){ 
            if(notPal(s,i,j)) continue; 

            sub.push_back(s.substr(i, j-i+1)); //s.substr(start, length)
            solve(s, j+1);
            sub.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;

    }
};