class Solution {
public:
    unordered_map<int, vector<int>> mp;
    bool isSubSeq(string &sup, string &sub){
        int n = sup.size();
        int m = sub.size();
        

        int p = -1;
        for(auto &c:sub){
            if(mp.find(c) == mp.end()) return false;

            vector<int> &v = mp[c];
            auto it  = upper_bound(v.begin(), v.end(), p);
            if(it == v.end()) return false;
            p = *it;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i=0; i<s.size(); i++)
            mp[s[i]].push_back(i);

        int count = 0;
        for(int i=0; i<words.size(); i++){
            if(isSubSeq(s, words[i]))
                count++;
        }
        return count;
    }
};