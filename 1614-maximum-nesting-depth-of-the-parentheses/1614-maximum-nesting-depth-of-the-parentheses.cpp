class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();  
        string ans;  
        int count=0;
        int max_depth=0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                count++;
                max_depth = max(max_depth,count);
            }
            if(s[i] == ')'){
                count--;
                max_depth = max(max_depth,count);
            }
        }
         return max_depth;
    }
};