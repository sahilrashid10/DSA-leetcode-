class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;

        vector<int> a1(26, 0), a2(26, 0);

        for(int i=0; i<s.size(); i++){
            a1[s[i]-'a']++;
            a2[t[i]-'a']++;
        }
        return a1 == a2;
    }
};