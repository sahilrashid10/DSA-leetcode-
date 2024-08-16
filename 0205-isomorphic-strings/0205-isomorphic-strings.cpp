class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        for(int i=0; i<n; i++){
            char si=s[i];      //ith char in s
            char ti=t[i];      //ith char in t
            if(mp1.find(si) != mp1.end() && mp1[si] != ti ||
            mp2.find(ti)!=mp2.end() && mp2[ti]!=si)
            return false;
            mp1[si]=ti;
            mp2[ti]=si;
        }
        return true;
    }
};