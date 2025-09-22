class Solution {
public:
    bool canEatAllBananas(vector<int>& piles, int mid, int h){

        int time = 0;
        for(int &pile:piles){
            int eaten = pile / mid;
            time += eaten;

            if(pile % mid != 0){
                time++;
            }
            if(time > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int minK = high;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canEatAllBananas(piles, mid, h)){
                high = mid - 1;
                minK = mid;
            }else
                low = mid + 1;
        }

        return minK;
    }
};