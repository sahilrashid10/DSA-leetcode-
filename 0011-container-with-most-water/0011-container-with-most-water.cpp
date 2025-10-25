class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxWater = 0;

        int l=0, r = h.size()-1;
        while(l < r){
            int water = min(h[l], h[r]) * (r - l);
            maxWater = max(maxWater, water);
            h[l] <= h[r] ? l++ : r--;
        }
        return maxWater;
    }
};