class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int lMax = 0, rMax = 0;   

        int total_water = 0;
        while(l<r){
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);

            if(height[l] <= height[r]){
                total_water += lMax - height[l];
                l++;
            }else{
                total_water += rMax - height[r];
                r--;
            }
        }   
        return total_water; 
    }
};


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> prefix(n, 0);
//         vector<int> suffix(n, 0);

//         prefix[0] = height[0];
//         suffix[n-1] = height[n-1];
//         for(int i=1; i<n; i++){
//             prefix[i] = max(prefix[i-1], height[i]);
//         }
//         for(int i=n-2; i>=0; i--){
//             suffix[i] = max(suffix[i+1], height[i]);
//         }

//         int total_water = 0;
//         for(int i=0; i<n; i++){
//             total_water += min(prefix[i], suffix[i]) - height[i];
//         }
//         return total_water;
//     }
// };