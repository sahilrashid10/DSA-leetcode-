class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        vector<int> m(10);
        for(int &num:nums)
            m[num]++;

        for(int i=1; i<=9; i++){
            if(m[i] == 0) continue;

            m[i]--;
            int dig = i;
                
            for(int j=0; j<=9; j++){
                if(m[j] == 0) continue;

                m[j]--;
                dig = dig*10 + j;  

                for(int k = 0; k<= 8; k += 2){

                    if(m[k] == 0) continue;
            
                    dig = dig*10 + k;
                    ans.push_back(dig);
                    dig /= 10;
                }
                m[j]++;
                dig /= 10;
            }
            m[i]++;
        }
        return ans;

    }
};

// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& nums) {
//         int n = nums.size();
//         set<int> s;
//         for (int i = 0; i < n; i++) {
//             if(nums[i] == 0) continue;
//             int num = nums[i];
//             for (int j = 0; j < n; j++) {
//                 if (i == j)
//                     continue;
//                 num = num * 10 + nums[j];
//                 for (int k = 0; k < n; k++) {
//                     if (k == i || k == j)
//                         continue;
//                     num = num * 10 + nums[k];
//                     if (num % 2 == 0)
//                         s.insert(num);
//                     num /= 10;
//                 }
//                 num /= 10;
//             }
//         }
//         vector<int> ans(s.begin(), s.end());
//         return ans;
//     }
// };