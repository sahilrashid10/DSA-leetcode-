class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    int n;
    bool isPalindrome(string &s){
        int start = 0, end = s.size() - 1;
        while(start<end)
            if(s[start++] != s[end--]) return false;

        return true;
  
    }
    void helper(string &s, int idx){
        if(idx == n){
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<n; i++){
            string s1 = s.substr(idx, i-idx+1);
            if(!isPalindrome(s1))
                continue;
            temp.push_back(s1);
            helper(s, i+1);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        helper(s, 0);
        return ans;
    }
};