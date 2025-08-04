class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=0, left = 0, right = 0;

        reverse(s.begin(), s.end());
        while(i<n){  

            while(i<n && s[i] != ' '){
                s[right] = s[i];
                i++;
                right++;
            }
            if(left < right){
                reverse(s.begin() + left, s.begin() + right);
                s[right] = ' ';
                right++;
                left = right;
            }
            i++;
        }
        s = s.substr(0, right-1);
        return s;
    }
};






// NOT OPTIMAL
// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> st;
//         int i=0;

//         while(i<s.size() && s[i] == ' ') i++;

//         string temp = "";
//         for(; i<s.size(); i++){
//             while(i< s.size() && s[i] != ' '){
//                 temp += s[i];
//                 i++;
//             }
//             if(temp != "")
//                 st.push(temp);

//             temp = "";
//         }
//         temp = "";
//         while(!st.empty()){
//             temp += st.top() + ' ';
//             st.pop();
//         }
//         s = temp.substr(0,temp.size()-1);
//         return s;
//     }
// };