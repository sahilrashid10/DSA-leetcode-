class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n = s.size();
        int i=0;
        while(i<n){
            string temp="";
            while(s[i] != ' ' && i<n){
                temp += s[i];
                i++;
            }
            if(!temp.empty()){
                if(ans.empty())
                ans = temp+ans;
                else
                ans = temp+' '+ans;
            }
                i++;
        }    
            return ans;
    }
};