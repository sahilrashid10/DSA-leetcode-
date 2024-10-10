class Solution{
public:
    double solve(double x, long n){

        if(n<0)
            return solve(1/x,-n);
        //base case
        if(n==0)
            return 1;
        //recursion
        if(n%2 == 0)                   //if n even
            return solve(x*x,n/2);     
        else                           //if odd
            return x*solve(x*x,n/2);
    }
    double myPow(double x, int n){
        double ans = solve(x, long(n));
        return ans;
    }
};