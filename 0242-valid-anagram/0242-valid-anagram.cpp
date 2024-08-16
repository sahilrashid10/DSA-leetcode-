class Solution {
public:
    bool isAnagram(string s, string t) {

//A. brute force 2 for loop T=O(N^2) S=O(1)
//B. sorting T=O(nlogn) S=O(1)
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)
        // return true;
        // return false;
//C. map T=O(N) S=O(N);
       unordered_map<char,int>mp;
       for(auto it:s){
        mp[it]++;
       }
       for(auto it:t){
        mp[it]--;
       }
       for(auto it:mp){
        if(it.second != 0)
        return false;
       }
       return true;
    }
};