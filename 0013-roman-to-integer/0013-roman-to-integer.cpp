class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int number = 0;
        for(int i=0; i<s.length(); i++){

            if(s[i] == '\0')
            break;

            if(mp[s[i]] < mp[s[i+1]]){
                number += mp[s[i]];
                number -= 2*mp[s[i]];
                }
            else
                number += mp[s[i]];    
            
        }
            return number;
        }
    };