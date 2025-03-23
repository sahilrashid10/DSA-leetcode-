class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num = 0, temp = x;

        while(temp > 0){
            int dig = temp % 10;
            if(INT_MAX/10 > num )
                num = num*10 + dig;
            else return false;
            temp /= 10;
        }
        return num == x;
    }
};