class Solution {
public:
    bool rotateString(string s, string goal) {
//  A)
        if(s.size() != goal.size())
        return false;
        return (s+s).contains(goal);
//  B)
        int n = s.size();
        //check if size's are equal
        // if(n != goal.size())
        // return false;
        // for(int i=0; i<n; i++){
        //     if(s == goal)
        //     return true;
        //     //try all rotations
        //     s = s.substr(1)+s[0]; //appending s[0] to sub string of s
        //                           // starting from index 1
        // }
        // return false;
    }
};