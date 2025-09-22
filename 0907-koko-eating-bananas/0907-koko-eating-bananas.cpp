class Solution {
public:
    bool canEatAllBananas(vector<int>& piles, int time, int h){

        int curTime = 0;
        for(int &pile:piles){
            int eaten = pile / time;
            curTime += eaten;
            if(pile % time != 0){
                curTime++;
            }
            if(curTime > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int minTime = 1;
        int maxTime = *max_element(piles.begin(), piles.end());
        int minK = maxTime;
        while(minTime <= maxTime){
            int time = minTime + (maxTime - minTime) / 2;

            if(canEatAllBananas(piles, time, h)){
                maxTime = time - 1;
                minK = time;
            }else
                minTime = time + 1;
        }

        return minK;
    }
};