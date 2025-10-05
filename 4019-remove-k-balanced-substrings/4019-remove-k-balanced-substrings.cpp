class Solution {
public:
    string removeSubstring(string str, int k) {
        int n = str.size();
        vector<pair<char, int>> s;
        
        for(auto &c:str){

            if(s.empty() || s.back().first != c){
                s.emplace_back(c, 1);
            }else
                s.back().second++;
            
            while(s.size() > 1 && s.back().first == ')' &&
                    s[s.size() - 2].first == '('){
                int countClose = s.back().second;
                int countOpen = s[s.size() - 2].second;

                int minRemoval = min(countClose/k, countOpen/k);
                if(minRemoval == 0) break;

                s.pop_back();
                s.pop_back();

                countOpen -= minRemoval*k;
                countClose -= minRemoval*k;

                if(countOpen > 0) s.emplace_back('(', countOpen);
                if(countClose > 0) s.emplace_back(')', countClose);
            }
        }
        string ans;
        for(auto &[c, f]:s){
            ans.append(f, c);
        }
        return ans;
    }
};


// class Solution {
// public:
//     string removeSubstring(string str, int k) {
//         int n = str.size();

//         stack<char> s;
        
//         for(auto &c:str){
//             s.push(c);

//             if(s.size() >= 2*k){
//                 stack<char> temp;
//                 int x = k;
//                 while(!s.empty() && s.top() == ')' && x>0){
//                     temp.push(s.top());
//                     s.pop();
//                     x--;
//                 }
//                 if(temp.size() == k){
//                     int x = k;
//                     while(!s.empty() && s.top() == '(' && x > 0){
//                         temp.push(s.top());
//                         s.pop();
//                         x--;
//                     }        
//                 }
//                 if(temp.size() != 2*k){
//                     while(!temp.empty()){
//                         s.push(temp.top());
//                         temp.pop();
//                     }
//                 }
//             }
//         }
//         string ans = "";
//         while(!s.empty()){
//             ans += s.top();
//             s.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };