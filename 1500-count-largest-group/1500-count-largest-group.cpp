class Solution {
public:
    int digitSum(int i){
        int sum = 0;
        while(i>0){
            int dig = i%10;
            i /= 10;
            sum += dig;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int> sums(37);
        for(int i=1; i<=n; i++) sums[digitSum(i)]++;

        int count = 1, maxi = INT_MIN;
        for(int &sum:sums){
            if(sum == maxi){
                count++;
            }else if(sum > maxi){
                count = 1;
                maxi = sum;
            }
        }
        return count;
    }
};
// class Solution {
// public:
    // int digitSum(int i){
    //     int sum = 0;
    //     while(i>0){
    //         int dig = i%10;
    //         i /= 10;
    //         sum += dig;
    //     }
    //     return sum;
    // }
//     int countLargestGroup(int n) {
//         if(n<10)    return n;
    
//         map<int, int> m;
//         for(int i=1; i<=n; i++){
//             int sum = digitSum(i);
//             m[sum]++;
//         }
//         int maxSize = INT_MIN;
//         for(auto &it:m){
//             if(it.second >= maxSize)
//                 maxSize = it.second;
//         }
//         int ans = 0;
//         for(auto &it:m){
//             if(it.second >= maxSize){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };