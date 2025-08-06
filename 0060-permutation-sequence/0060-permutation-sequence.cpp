class Solution {
public:
    string getPermutation(int n, int k) {
        // n+1 size vector
        vector<int> nums;
        string ans; 
        for(int i = 1; i <= n; i++)
            nums.push_back(i);

        // store factorials to avoid recomputation
        vector<int> fact(n+1, 1);
        for(int i = 1; i <= n; i++)
            fact[i] = fact[i-1] * i;

        k--; // convert k to 0-based indexing

        // keep picking until nums is empty
        while (!nums.empty()) {
            //permutations without starting number in each respective permutation
            //[1,2,3,4]
            //6
            int singlePermutation = fact[nums.size() - 1];
            //4*6=24
            // int totalPermutations =  nums.size()*singlePermutation; 
            //16/6 = 2;
            int requiredIndex = k / singlePermutation;
            //16 % 6 = 4
            k = k % singlePermutation;

            char reqNum = nums[requiredIndex] + '0';
            ans += reqNum;
            nums.erase(nums.begin() + requiredIndex);
        }
        return ans;
    }
};


// n! * n time,   n space
// class Solution {
// public:
//     string ans;
//     string temp;
//     unordered_map<char, int>m;
//     void helper(int n, int &k, int count){
//         if(count > n){
//             k--;
//             if(k == 0)
//                 ans = temp;
//             return;
//         }
//         for(int i = 1; i<=n && k > 0; i++){
//             char c = '0' + i;
//             if(m[c] != 1){
//                 m[c] = 1;
//                 temp += c;
//                 helper(n, k, count+1);
//                 temp.pop_back();
//                 m[c] = 0;
//             }
//         }
//     }
//     string getPermutation(int n, int k) {
//         helper(n, k, 1);
//         return ans;
//     }
// };
