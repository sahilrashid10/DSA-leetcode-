/*OPTIMAL  ANS O(1), space complexity*/
class Solution {
public:
    int trap(vector<int>& height) {
    int l=0,lmax=height[l];
    int n = height.size();
    int r=n-1, rmax = height[r];
    int total_water=0;
    while(l!=r && l<r){
        if(height[l]<height[r]){
            int water_in_building = lmax - height[l];
            if(water_in_building < 0)
                water_in_building = 0;
            total_water += water_in_building;
            lmax = max(lmax, height[l]);
            l++;
        }
        else if(height[l]>height[r]){
            int water_in_building = rmax - height[r];
            if(water_in_building < 0)
                water_in_building = 0;
            total_water += water_in_building;
            rmax = max(rmax, height[r]);
            r--;
        }else{
            lmax = max(lmax, height[l]);
            l++;
        }
    }
    return total_water;
    }
};

/************************************************************************
BRUTE FORCE T O(3n), S O(2n)*/
// class Solution {
// public:
//     int n;
//     vector<int> PrefixMax(const vector<int>& h){
//         vector<int>a(n);
//         a[0]=h[0];
//         for(int i=1; i<n; i++){
//             a[i] = max(a[i-1],h[i]);
//         }
//         return a;
//     }
//     vector<int> SuffixMax(const vector<int>& h){
//         vector<int>a(n);
//         a[n-1]=h[n-1];
//         for(int i=n-2; i>=0; i--){
//             a[i] = max(a[i+1],h[i]);
//         }
//         return a;
//     }
//     int trap(vector<int>& h) {
//         n = h.size();
//         if(n==1)
//             return 0;
//         int water = 0;
//         for(int i=0; i<n; i++){
//             vector<int> leftMax = PrefixMax(h);
//             vector<int> rightMax = SuffixMax(h);
//             if(h[i]<leftMax[i] && h[i]<rightMax[i])
//                 water += min(leftMax[i], rightMax[i])-h[i];
//         }
//         return water;
//     }
// };