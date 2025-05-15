class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string>result = {words[0]};

        for(int i = 1; i < n; i++) {
            int lastGroup = groups[i-1];
            if(groups[i] == lastGroup) 
                    continue;

            result.push_back(words[i]);
        }
        
        return result;
    }
};


// class Solution {
// public:
//     vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
//         int n = words.size();
//         vector<string> result;

//         for(int i = 0; i < n; i++) {
//             vector<string> temp = {words[i]};
//             int lastGroup = groups[i];

//             for(int j = i + 1; j < n; j++) {
//                 if(groups[j] == lastGroup) 
//                     continue;
                    
//                 temp.push_back(words[j]);
//                 lastGroup = groups[j];
//             }

//             if(temp.size() > result.size()) {
//                 result = temp;
//             }
//         }

//         return result;
//     }
// };
