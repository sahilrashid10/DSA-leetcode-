class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";
        int i=0;
         while(i<strs[0].size()){
            char match = strs[0][i];
            for(int j = 0; j<strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != match)
                    return ans;
            }
            ans += match;
            i++;
        }
        return ans;
    }
};