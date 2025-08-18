class Solution {
public:
    int strStr(string w, string p) {
        int n = w.size();
        int m = p.size();
        if(m == 0) return 0;

        // Step 1: Build LPS array
        vector<int> LPS(m, 0);
        int len = 0, i = 1;
        while(i < m) {
            if(p[i] == p[len]) {
                LPS[i] = len + 1;
                len++;
                i++;
            } else {
                if(len > 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: KMP search
        int j = 0; // index for pattern
        i = 0;     // index for text
        while(i < n) {
            if(w[i] == p[j]) {
                i++;
                j++;
                if(j == m) return i - j; // found match
            } else {
                if(j > 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};
