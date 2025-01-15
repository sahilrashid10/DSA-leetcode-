//OPTIMAL SOL T=O(N) S=O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0; 
        int max_len = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0)
                count++;

            while (count > k) { 
                if (nums[l] == 0)
                    count--;
                l++;
            }
            max_len = max(max_len, r - l + 1); 
        }
        return max_len;
    }
};

//BETTER SOLUTION T=O(N) S=O(K)
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         queue<int>q;
//         int max_len=0;
//         int l=0,r=0;
//         for(int r=0; r<nums.size(); r++){
//             if(nums[r]==0)
//                 q.push(r);
//             if(q.size()<=k)
//                  max_len = max(max_len, r-l+1);
//             else{
//                 l = q.front()+1;
//                 q.pop();
//             }
//         }
//         return max_len;
//     }
// };
//  BRUTE FORCE T=O(N^2) S=O(1)
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int max_len=0;
//         for(int i=0; i<nums.size(); i++){
//             int count=0;
//             int temp = k;
//             for(int j=i; j<nums.size(); j++){
//                 if(nums[j]==0 && temp>0){
//                     temp--;
//                     count++;
//                 }
//                 else if(nums[j]!=0)
//                     count++;
//                 else
//                     break;
//                 max_len=max(max_len, count);
//             }
//         }
//         return max_len;
//     }
// };