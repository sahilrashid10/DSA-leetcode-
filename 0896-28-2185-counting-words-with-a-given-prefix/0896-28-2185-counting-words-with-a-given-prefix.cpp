class Solution {
public:
    bool isPrefix(const string& w, const string& p){
        int i=0;
        while(i<p.size()){
            if(w[i]!=p[i])
                return false;
            i++;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(int i=0; i<words.size(); i++){
            if(words[i].size()<pref.size())
                continue;
            if(isPrefix(words[i], pref))
                ans++;
        }
        return ans;
    }
};