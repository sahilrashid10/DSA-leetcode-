class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suffix(n);
        suffix[n-1] = s[n-1];

        for(int i=n-2; i>=0; i--){
            if(s[i] < suffix[i+1])
                suffix[i] = s[i];
            else suffix[i] = suffix[i+1];
        }

        stack<char> st;
        string ans;
        int i=0;
        while(i<n){
            st.push(s[i]);
            while(i<n && !st.empty() && (i==n-1 || st.top() <= suffix[i+1])){
                ans += st.top();
                st.pop();
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};