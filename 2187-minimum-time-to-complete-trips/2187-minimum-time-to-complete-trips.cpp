class Solution {
public:
    bool canMakeit(vector<int>& time, int tt, long long m){
        long long actual_trips=0;
        for(auto &it:time){
            actual_trips += m/it;
            if(actual_trips >= tt)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s=1;
        long long e= (long long)*min_element(begin(time), end(time))*totalTrips;
        while(s<=e){
            long long m=s+(e-s)/2;
            if(canMakeit(time, totalTrips, m))
                e=m-1;
            else s=m+1;
        }
        return s;
    }
};