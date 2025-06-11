class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;

        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;

                vector<int> best(4, INT_MAX);

                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;

                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);

                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] = min(best[left_status], prev_a - prev_b);

                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }

                    int right_status = getStatus(cnt_a, cnt_b);
                    int required_status = right_status ^ 0b10;

                    if (best[required_status] != INT_MAX) {
                        ans = max(ans, cnt_a - cnt_b - best[required_status]);
                    }
                }
            }
        }

        return ans;
    }

private:
    // Helper to get parity status as a 2-bit number
    int getStatus(int cnt_a, int cnt_b) {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    }
};




/*BRUTE FORCE: TIME:O(N^2), SPACE=O(1)*/
// class Solution {
// public:
//     int maxDifference(string s, int k) {
//         int n = s.size();
//         int maxDiff = INT_MIN;

//         for (int i = 0; i <= n - k; ++i) {
//             vector<int> freq(5, 0);
//             for (int j = i; j < n; ++j) {
//                 freq[s[j] - '0']++;
//                 if (j - i + 1 >= k) {
//                     for (int a = 0; a < 5; ++a) {
//                         if (freq[a] % 2 == 1) { // odd frequency
//                             for (int b = 0; b < 5; ++b) {
//                                 if (a != b && freq[b] >= 2 && freq[b] % 2 == 0) {
//                                     maxDiff = max(maxDiff, freq[a] - freq[b]);
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         return maxDiff;
//     }
// };
