class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;     // overall gas - cost balance
        int tank = 0;      // current fuel in tank
        int start = 0;     // candidate start index
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            // if tank goes negative, we cannot reach station i+1 from current start
            if (tank < 0) {
                start = i + 1;  // reset start to next station
                tank = 0;       // reset tank
            }
        }

        return total >= 0 ? start : -1;
    }
};
