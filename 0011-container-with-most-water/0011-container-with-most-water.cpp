class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int i=0, j=height.size()-1;
        while(i<j){
            int temp = min(height[i], height[j]) * (j-i);
            maxi = max(maxi, temp);
            if(height[j] < height[i]) j--;
            else i++;
        }
        return maxi;
    }
};