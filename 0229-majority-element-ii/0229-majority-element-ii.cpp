class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int n1 = 0, n2 = 0;

        for(int i=0; i<nums.size(); i++){
            if(c1 == 0 && n2 != nums[i]) n1 = nums[i];
            if(c2 == 0 && n1 != nums[i])
                n2 = nums[i];

            if(nums[i] == n1) c1++;
            else if(nums[i] == n2) c2++;
            else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1 = 0;
        c2 = 0;
        for(int &num : nums){
            if(num == n1)
                c1++;
            else if(num == n2)
                c2++;
        }
        if(c1 > nums.size()/3) ans.push_back(n1);
        if(c2 > nums.size()/3) ans.push_back(n2);
        return ans;

    }
};


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {

//         sort(nums.begin(), nums.end());
//         vector<int> ans;
//         int i=0;
    
//         while(i<nums.size()){
//             int num = nums[i];
//             int freq = 1;
//             i++;
//             while(i<nums.size() && num == nums[i]){
//                 freq++;
//                 i++;
//             }
//             if(freq > nums.size()/3)
//                 ans.push_back(num);
//         }
//         return ans;
//     }
// };