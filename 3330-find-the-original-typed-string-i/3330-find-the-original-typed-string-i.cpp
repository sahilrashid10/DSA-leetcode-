// class Solution {
// public:
//     int possibleStringCount(string word) {
//         unordered_map<char, int>mp;
//         for(int i=0; i<word.size(); i++){
//             mp[word[i]]++;
//         }
//         int sum=1;
//         for(auto it:mp){
//             if(it.second > 1)
//             sum += it.second-1;
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int possibleStringCount(string word) {
        int i,j,count;
        count=i=j=0;
        while(i<word.size() &&j<word.size()){
            if(word[i]==word[j]) {count++; j++;}
            else {i=j; j++;}
        }
        return count;
    }
};