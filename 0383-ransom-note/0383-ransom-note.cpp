class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> f(26, 0);
        for(char &c:magazine)
            f[c - 'a']++;
        for(char &c:ransomNote){
            f[c - 'a']--;
            if(f[c - 'a'] < 0) return false;
        }
        return true;
        
    }
};