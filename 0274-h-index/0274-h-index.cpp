// O(n) time and space
class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> totalCit(n+1, 0);
        for(int i=0; i<n; i++){
            if(nums[i] < n)
                totalCit[nums[i]]++;
            else totalCit[n]++;
        }
        int count = 0;
        for (int i = n; i >=0; i--) {
            count += totalCit[i];
            if (i <= count) {
                return i;   
            }
        }

        return 0;  
    }
};
// nlogn time and 1 space
// class Solution {
// public:
//     int hIndex(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int hCand = 0;
//         for (int i = 0; i < n; i++) {
//             int hCand = n - i; 
//             if (nums[i] >= hCand) {
//                 return hCand;   
//             }
//         }

//         return hCand;  
//     }
// };
