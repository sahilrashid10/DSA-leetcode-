class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> values;
        for (int i = 0; i < nums2.size(); i++) {
            values.push_back({nums2[i], nums1[i]}); 
        }

        sort(values.begin(), values.end(), [](auto &a, auto &b) {
            return a.first > b.first; 
        });

        priority_queue<int, vector<int>, greater<int>> q; // min-heap
        long long sum = 0;

        // take first k
        for (auto &[num2, num1] : values) {
            if (q.size() == k) break;
            q.push(num1);        
            sum += num1;  
                  
        }

        long long ans = sum * values[k-1].first;

        // process the rest
        for (int i = k; i < nums2.size(); i++) {
            int num2 = values[i].first;
            int num1 = values[i].second;

            sum += num1;        
            sum -= q.top(); q.pop();   
            q.push(num1);      

            ans = max(ans, sum * num2);   
        }

        return ans;
    }
};
