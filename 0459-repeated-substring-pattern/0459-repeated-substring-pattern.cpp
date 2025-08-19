class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n, 0);

        lps[0] = 0;
        int len = 0;
        int i=1;
        while(i<n){
            if(s[i] == s[len]){
                lps[i] = len+1;
                len++;
                i++;
            }else{
                if(len > 0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps[n-1] > 0 && (n % (n - lps[n-1]) == 0); 
    }
};