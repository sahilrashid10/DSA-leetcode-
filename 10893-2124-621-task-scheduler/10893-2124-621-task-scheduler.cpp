class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> m(26, 0);  // map
        priority_queue<int> H; // ma-Heap
        int time = 0;
        for (int i = 0; i < tasks.size(); i++)
            m[tasks[i] - 'A']++;

        for (int i = 0; i < 26; i++) {
            if (m[i] > 0)
                H.push(m[i]);
        }

        while (!H.empty()) {

            vector<int> temp;
            for (int i = 1; i <= k + 1 && !H.empty(); i++) {
                int cur = H.top();
                H.pop();
                cur--;
                temp.push_back(cur);
            }

            for (int& it : temp) {
                if (it > 0)
                    H.push(it);
            }

            if (H.empty()) {
                time += temp.size();
            } else
                time += k + 1;
        }
        return time;
    }
};