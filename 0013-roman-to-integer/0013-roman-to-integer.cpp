class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;
        char prev = '*';
        for(char &c:s){
            if(prev != '*' && m[c] > m[prev]){
                ans += m[c] - 2*m[prev];
            }else
                ans += m[c];
            prev = c;
        }
        return ans;
    }
};