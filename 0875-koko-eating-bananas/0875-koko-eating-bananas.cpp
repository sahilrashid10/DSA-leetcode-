class Solution {
public:

    bool canEatAll(vector<int>& piles, int h, int m){
        int time_taken=0;
        for(auto &it: piles){
            time_taken += it/m;
            if(it%m != 0)
                time_taken++;
            if(time_taken>h)
                return false;
        }
        return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e = *max_element(begin(piles), end(piles));
        while(s<=e){
            int m = (s+e)/2;
            if(canEatAll(piles, h, m))
                e = m-1;
            else s = m+1;
        }
    return s;
    }
};