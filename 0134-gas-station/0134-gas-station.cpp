class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int canTravel = accumulate(gas.begin(), gas.end(), 0) -
        accumulate(cost.begin(), cost.end(), 0);
        if(canTravel < 0) return -1;

        int s = 0;
        int cg = 0;
        for(int i=0; i<n; i++){
            cg += gas[i] - cost[i];
            if(cg < 0){
                s = (i+1) % n;
                cg = 0;
            }
        }
        return s;
    }
};

/*
starting greedily at an index doesn't work
gas =
[5,8,2,8]
cost =
[6,5,6,6]

Use Testcase
Output
-1
Expected
3

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0;
        int n = gas.size();
        int maxVal = INT_MIN;
        for(int i=0; i<n; i++){
            if(gas[i] - cost[i] > maxVal){
                s = i;
                maxVal = gas[i] - cost[i];
            }
        }

        int i=s;
        int ng = 0;
        int flag = 1;
        while(i != s || flag){
            flag = 0;
            int cg = gas[i];
            ng += cg - cost[i];
            if(ng < 0) return -1;
            i = (i+1) % n;
        }
        return s == i? s:-1;
    }
};
*/