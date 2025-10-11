class Solution {
public:
    bool isHappy(int n) {
        if(n < 0) return false;
        if(n == 1) return true;
        unordered_map<int, int>m;
        while(m.find(n) == m.end()){
            m[n] = 1;
            int k = n;
            long long sum = 0;
            while(k > 0){
                int dig = k % 10;
                sum += (dig*dig);
                k /= 10;
            }
            if(sum == 1) return true;
            n = sum;
        }
        return false;
    }
};