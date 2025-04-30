class Solution {
public:
    int p;
    void getLps(const string &b, vector<int> &lps) {
        int len = 0, i = 1;
        lps[0] = 0;
        while (i < p) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool checkIfPnst(const string &s, const string &b) {
        int t = s.size();
        vector<int> lps(p);
        getLps(b, lps);

        int i = 0, j = 0;
        while (i < t) {
            if (s[i] == b[j]) {
                i++; j++;
            } else {
                if (j != 0) j = lps[j-1];
                else        i++;
            }
            if (j == p) {
                return true;    // correct: found b in s
            }
        }
        return false;           // correct: never found b
    }

    int repeatedStringMatch(string a, string b) {
        p = b.size();
        int times = 0;
        string s;
        int maxRepeats = (b.size() + a.size() - 1) / a.size() + 1;

        while (times < maxRepeats) {
            s += a;
            times++;
            if (s.size() >= b.size() && checkIfPnst(s, b)) {
                return times;
            }
        }
        return -1;
    }
};

