class Solution {
public:
    unordered_set<string> dict;
    int n;
    vector<int> dp;
    bool canBreak(string &s, int idx){
        if(idx == n) return true;

        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        for(int i=idx; i<n; i++){
            temp += s[i];
            if(dict.find(temp) != dict.end()){
                 if(canBreak(s, i+1))
                    return dp[i] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        n = s.size();
        dp.resize(n, -1);
        return canBreak(s, 0);
    }
};