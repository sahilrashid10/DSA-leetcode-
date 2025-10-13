class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        int k = 0;
        int i=0;
        while(k < m){
            if(s[i] == t[k]) i++;
            k++;
        }
        return i == n;
    }
};