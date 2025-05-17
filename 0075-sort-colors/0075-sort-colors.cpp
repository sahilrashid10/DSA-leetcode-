class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;

            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         vector<int> temp(nums.size(), 1);
//         int i=0, j = temp.size()-1;
//         for(int k=0; k<nums.size(); k++){
//             if(nums[k] == 0){
//                 temp[i] = 0;
//                 i++;
//             }
//             if(nums[k] == 2){
//                 temp[j] = 2;
//                 j--;
//             }
//         }
//         nums = temp;
//     }
// };