class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return 0;

        unordered_map<char, int> m;
        unordered_map<char, int> used;
        
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) != m.end()){
                if(t[i] != m[s[i]])
                    return 0;
            }else if(used.find(t[i]) != used.end() && used[t[i]] != s[i])
                return 0;
            m[s[i]] = t[i]; 
            used[t[i]] = s[i]; 

        }
        
        return 1;
    }
};