class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0], fast=nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         if(nums.size()==1)
//             return nums[0]; 
//         for(int i=1; i<nums.size(); i++){
//             int temp = nums[i-1];
//             if(temp == nums[i])
//                 return nums[i];
//         }
//         return 0;
//     }
// };