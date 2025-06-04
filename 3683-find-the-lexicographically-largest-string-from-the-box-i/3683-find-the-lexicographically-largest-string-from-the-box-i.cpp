class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();

        if(numFriends == 1) return word;
        int i=0, j=1;
        string s;
        
        int len = n - (numFriends - 1);
        while(j<n){
            int k = 0;
            while(j+k < n && word[j+k] == word[i+k])
                k++;
            if(j+k < n && word[i+k] < word[j+k]){
                i = j;
                j = j+1;
            }else{
                j++;
            }
        }
        int maxLen = min(n - i, len);
        return word.substr(i, len);
    }
};

// TIME : O(n^2)  S : O(n)
// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         int n = word.size();
//         if(numFriends == 1) return word;
//         string s;

//         int maxLen = n - numFriends + 1;
//         for(int i=0; i<n; i++){
//             int len = min(maxLen, n-i);
//             s = max(word.substr(i, len), s);
//         }
//         return s;
//     }
// };