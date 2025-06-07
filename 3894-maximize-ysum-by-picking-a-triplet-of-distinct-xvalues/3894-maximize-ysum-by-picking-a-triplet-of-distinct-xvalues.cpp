class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        // Build a max-heap of (value, type) pairs directly
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < (int)y.size(); ++i) {
            pq.emplace(y[i], x[i]);
        }

        unordered_set<int> seen;
        int sum = 0;

        // Extract until we have 3 distinct types or the heap is exhausted
        while (!pq.empty() && seen.size() < 3) {
            auto [value, type] = pq.top();
            pq.pop();
            if (seen.insert(type).second) {
                sum += value;
            }
        }

        return (seen.size() == 3) ? sum : -1;
    }
};
