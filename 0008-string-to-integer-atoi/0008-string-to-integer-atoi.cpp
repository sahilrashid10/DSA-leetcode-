class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0, sign = 1, ans = 0;

        // skip leading spaces
        while(i < n && s[i] == ' ') i++;

        // handle sign
        if(i < n && s[i] == '-') { sign = -1; i++; }
        else if(i < n && s[i] == '+') i++;

        // skip leading zeros
        while(i < n && s[i] == '0') i++;

        // parse digits
        while(i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            // check overflow
            if(ans > (INT_MAX - digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};
