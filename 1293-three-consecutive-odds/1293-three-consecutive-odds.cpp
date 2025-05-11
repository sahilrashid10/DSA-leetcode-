class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int &num:arr){
            if(num % 2 == 0 )
                ans = 0;
            else ans++;
            if(ans == 3)
                return true;
        }
        return false;
    }
};



// class Solution {
// public:
//     bool threeConsecutiveOdds(vector<int>& arr) {
//         if (arr.size() < 3)
//             return false;
//         for (int i = 0; i < arr.size() - 2; i++) {
//             if (arr[i] & 1 && arr[i + 1] & 1 && arr[i + 2] & 1)
//                 return true;
//         }
//         return false;
//     }
// };