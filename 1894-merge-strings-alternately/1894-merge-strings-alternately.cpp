class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      string ans = "";
      int n = word1.length();
      int m = word2.length();
      int i=0,j=0;

      while (n>i || m>j){
       if(i<n) ans += word1[i];
        if (j<m)ans += word2[j];
        i++;
        j++;
      }
      return ans;
    }
};