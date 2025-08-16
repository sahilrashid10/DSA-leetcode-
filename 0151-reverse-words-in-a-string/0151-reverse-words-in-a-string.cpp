class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0, k = 0;

        // 1. Reverse the whole string
        reverse(s.begin(), s.end());

        // 2. Process each word in-place
        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // mark the start of the word
            k = j;

            // copy the word forward (overwrite spaces)
            while (i < n && s[i] != ' ') s[j++] = s[i++];

            // reverse the word
            reverse(s.begin() + k, s.begin() + j);

            // add a single space after the word
            if (j < n) s[j++] = ' ';
        }

        // remove trailing spaces
        if (j > 0 && s[j-1] == ' ') j--;
        s.erase(s.begin() + j, s.end());

        return s;
    }
};

// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.size();
//         string temp = "";
//         string ans = "";

//         int i = n - 1;
//         while (i >= 0) {
//             while (i >= 0 && s[i] == ' ')
//                 i--;

//             while (i >= 0 && s[i] != ' ') {
//                 temp += s[i];
//                 i--;
//             }
//             if (!temp.empty()) {
//                 reverse(temp.begin(), temp.end());
//                 ans = ans + ' ' + temp;
//                 temp = "";
//             }
//         }
//         ans.erase(0, 1);
//         return ans;
//     }
// };
// Exactly — you’ve got it! Let me summarize precisely:

// Outer loop (while(i >= 0)): Each character is visited once → O(n).

// Reversing temp for each word: Each character is reversed exactly once → total
// O(n).

// ans = ans + ' ' + temp:

// Each concatenation creates a new string and copies the entire current ans
// plus the new word.

// If there are many words, the total copied characters over all concatenations
// sum up to roughly n + (n + ...) = O(n²) in the worst case.

// ✅ So, overall complexity:

// �(�)
//  (outer loop) + �(�)
//  (reversals) + �(� 2)
//  (string concatenation) = �(� 2) O(n) (outer loop) + O(n) (reversals) +
//                            O(n 2) (string concatenation) = O(n 2)