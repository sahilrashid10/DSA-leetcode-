 class Solution {
public:
    int myAtoi(string s) {
//  ROUND 1
    //     long ans = 0;
    //     int sign = 1;
    //     int i = 0;

    //     while (s[i] == ' ') i++;

    //     if (s[i] == '-' || s[i] == '+') {
    //         sign = (s[i] == '-') ? -1 : 1;
    //         i++;
    //     }
    //     while (i < s.length() && isdigit(s[i])) {
    //         ans = ans * 10 + (s[i] - '0');
    //         if (ans*sign <= INT_MIN) return INT_MIN;
    //         if (ans*sign >= INT_MAX) return INT_MAX;
    //         i++;
    //     }
    //     return ans * sign;
// ROUND 2 (brute force)
    int n = s.size();
    int ans = 0;    // ans long lele sol optimal hojaiga bcz INT_MAX/10 NAI SEEDHA ans >= INT_MAX \U0001f636 
    int sign = 1;
    int i = 0;
    while(s[i]==' ')
        i++;
    if(s[i] == '-'||s[i]=='+'){
        sign= (s[i]=='-')?-1:1;
        i++;            
        }
    while(s[i]=='0')
        i++;
    while(i<n && s[i]>='0' && s[i]<='9'){
        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i]>'7')){
            return (sign == 1)?INT_MAX:INT_MIN;
            }
        else
            ans = ans*10 + (s[i]-'0');
        i++;
        }
    return ans*sign;

    }
};