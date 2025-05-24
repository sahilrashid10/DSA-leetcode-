class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int idx = 0;
        for(string &s:words){

            for(char &c:s){
                if(c == x){
                    ans.push_back(idx);
                    break;
                }
            }
            idx++;
        }
        return ans;
    }
};