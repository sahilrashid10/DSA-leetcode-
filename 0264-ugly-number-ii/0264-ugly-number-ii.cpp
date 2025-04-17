class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)  return 1;

        vector<int> uglyArray(n+1);

        int u2, u3, u5;
        int i2=1, i3=1, i5=1;
        uglyArray[1] = 1;

        for(int i=2; i<=n; i++){
            u2 = uglyArray[i2] * 2;
            u3 = uglyArray[i3] * 3;
            u5 = uglyArray[i5] * 5; 
            
            int nextUgly = min(u2, min(u3, u5));
            uglyArray[i] = nextUgly;

            if(nextUgly == u2) i2++;
            if(nextUgly == u3) i3++;
            if(nextUgly == u5) i5++;
        }
        return uglyArray[n];
    }
};