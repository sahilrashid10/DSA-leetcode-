class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        int left = 0;
        for(int right=1; right<n; right++){
            if(word[right] == word[left])
                ans++;
            left++;
        }
        return ans;
    }
};