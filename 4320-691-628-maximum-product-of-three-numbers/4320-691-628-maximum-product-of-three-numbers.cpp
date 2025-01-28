//OPTIMAL T=O(n) S=O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Initialize the largest and smallest values
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN; 
        int n1 = INT_MAX, n2 = INT_MAX;         

        for (int x : nums) {
            // Update largest three numbers
            if (x > m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } else if (x > m2) {
                m3 = m2;
                m2 = x;
            } else if (x > m3) {
                m3 = x;
            }

            // Update smallest two numbers
            if (x < n1) {
                n2 = n1;
                n1 = x;
            } else if (x < n2) {
                n2 = x;
            }
        }

        // Calculate both potential maximum products
        int product1 = m1 * m2 * m3; 
        int product2 = m1 * n1 * n2; 

        return max(product1, product2);
    }
};
//BRUTE FORCE T=O(n*logn) S=O(1)
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int p1=nums[n-1], p2=1, j=n-1, i=0;
//         while(i<3){
//             p2 *= nums[j];
//             if(i<2)
//                 p1 *= nums[i];
//             j--;
//             i++;
//         }
//         return max(p1, p2);
//     }
// };
