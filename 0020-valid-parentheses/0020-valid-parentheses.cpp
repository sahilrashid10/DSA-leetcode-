class Solution {
public:
    bool isValid(string s) {

        stack<int> st;
        for(char &ch:s){
            if(ch == '}' || ch == ']' || ch == ')')
                if(st.empty()) return false;
                else if((ch == ')' && st.top() != '(') ||
                    (ch == '}' && st.top() != '{')||
                    (ch == ']' && st.top() != '['))
                    return false;
                else st.pop();
            else{
                st.push(ch);
            }
        }
        return st.empty();
    }
};