class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(auto &a: asteroids){
            while(!s.empty() && a<0 && s.top()>0){
                if(abs(a)<s.top())
                    a=0;
                else if(abs(a)>s.top())
                    s.pop();
                else{
                    s.pop();
                    a=0;
                }
            }
            if(a!=0)
                s.push(a);
        }
        vector<int>ans(s.size());
        for(int i=s.size()-1; i>=0; i--){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
//T=O(n^2) bcz of erase() method
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& a) {
//      stack<int>s;
//      vector<int>ans = a;
//      int n = ans.size();
//      int i=0;
//      while(i<n){
//         while(i<n && ans[i]>0){
//             s.push(ans[i]);
//             i++;
//             }
//         if(i<n && !s.empty()){
//             int x = abs(ans[i]);
//             if(x < s.top()){
//                 ans[i]=1001;
//                 i++;
//                 }
//             else if(x > s.top())
//                 s.pop();
//             else{
//                 s.pop();
//                 ans[i]=1001;
//                 i++;
//             }
//         }
//         else 
//             i++;
//      }
//      for(int i=n-1; i>=0; i--){
//         if(!s.empty()){
//             if(ans[i]==1001)
//                 ans.erase(ans.begin()+i);
//             else if(s.top()== ans[i])
//                 s.pop();
//             else
//                 ans.erase(ans.begin()+i);
//         }
//         else{
//             if(ans[i]>0){
//                 ans.erase(ans.begin()+i);
//             }
//         }
//      }
//      return ans;   
//     }
// };