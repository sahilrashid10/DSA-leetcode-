#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long base = 26;
    const long long mod = 1e9 + 7; // large prime to avoid collisions
    int m;

    // Modular exponentiation
    long long modPow(long long b, long long e, long long mod) {
        long long res = 1;
        b %= mod;
        while (e > 0) {
            if (e % 2) res = (res * b) % mod;
            b = (b * b) % mod;
            e /= 2;
        }
        return res;
    }

    // Check actual match
    bool matchStrings(const string &text, const string &pattern, int start) {
        for (int i = 0; i < m; i++) {
            if (text[start + i] != pattern[i]) return false;
        }
        return true;
    }

    // Rabin-Karp on a single string
    bool rabinKarpSearch(const string &text, const string &pattern) {
        int n = text.size();
        if (n < m) return false;

        long long hashPattern = 0, hashText = 0;
        long long power = modPow(base, m - 1, mod);

        // initial hashes
        for (int i = 0; i < m; i++) {
            hashPattern = (hashPattern * base + (pattern[i] - 'a')) % mod;
            hashText = (hashText * base + (text[i] - 'a')) % mod;
        }

        for (int i = 0; i <= n - m; i++) {
            if (hashText == hashPattern && matchStrings(text, pattern, i))
                return true;

            // slide window
            if (i < n - m) {
                hashText = hashText - ((text[i] - 'a') * power);
                hashText = (hashText * base + (text[i + m] - 'a')) % mod;
            }
        }
        return false;
    }

public:
    int repeatedStringMatch(string a, string b) {
        m = b.size();
        string repeated = a;
        int count = 1;

        // keep appending until repeated string is long enough
        while (repeated.size() < a.size() + b.size()) {
            if (rabinKarpSearch(repeated, b)) return count;
            repeated += a;
            count++;
        }

        return rabinKarpSearch(repeated, b) ? count : -1;
    }
};




// USING KMP
// class Solution {
// public:
//     // Builds the LPS (Longest Prefix Suffix) array for pattern
//     vector<int> buildLPS(const string &pattern) {
//         int m = pattern.size();
//         vector<int> lps(m, 0);
        
//         int len = 0; // length of current longest prefix
//         for (int i = 1; i < m; ) {
//             if (pattern[i] == pattern[len]) {
//                 lps[i] = ++len;
//                 i++;
//             } else {
//                 if (len > 0) {
//                     len = lps[len - 1];
//                 } else {
//                     lps[i] = 0;
//                     i++;
//                 }
//             }
//         }
//         return lps;
//     }

//     // KMP string matching, returns true if pattern found in text
//     bool kmpSearch(const string &text, const string &pattern, const vector<int> &lps) {
//         int n = text.size(), m = pattern.size();
//         int i = 0, j = 0;
        
//         while (i < n) {
//             if (text[i] == pattern[j]) {
//                 i++, j++;
//                 if (j == m) return true; // found pattern
//             } else {
//                 if (j > 0) {
//                     j = lps[j - 1];
//                 } else {
//                     i++;
//                 }
//             }
//         }
//         return false;
//     }

//     int repeatedStringMatch(string a, string b) {
//         int n = a.size(), m = b.size();
//         vector<int> lps = buildLPS(b);

//         string repeated = a;
//         int count = 1;

//         // We only need to repeat until length >= m + n (pigeonhole principle)
//         while (repeated.size() <= m + n) {
//             if (kmpSearch(repeated, b, lps)) return count;
//             repeated += a;
//             count++;
//         }
//         return kmpSearch(repeated, b, lps) ? count : -1;
//     }
// };
