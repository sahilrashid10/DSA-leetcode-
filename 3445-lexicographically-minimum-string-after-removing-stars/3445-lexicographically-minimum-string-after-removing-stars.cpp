// operator(): used to make a functor, basically making an object behave like a function
class Solution {
public:
    struct compare{
        bool operator()(pair<char, int> &a, pair<char, int> &b){
            if(a.first != b.first)
                return a.first > b.first;
            else
                return a.second < b.second;
        }
    };
    string clearStars(string s) {
        // min-heap definition
        using node = pair<char, int>;
        priority_queue<node, vector<node>, compare> prev_smaller; 

        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                auto[letter, index] = prev_smaller.top();
                prev_smaller.pop();

                s[index] = '*';
            }else{
                prev_smaller.push({s[i], i});
            }
        }
        string ans;
        for(char &c:s){
            if(c != '*')
                ans += c; 
        }
        return ans;
    }
};


// class Solution {
// public:
//     string clearStars(string s) {
//         int n = s.size();
//         vector<int> to_delete;
//         unordered_map<char, vector<int>> mp;
        
//         //1.iterate over the string
//         for(int i=0; i<n; i++){
//             //2. 2-conditions
//                 // 2.a) if '*'
//                 if(s[i] == '*'){
//                     to_delete.push_back(i);
//                     for(char c = 'a'; c <= 'z'; c++){
//                         if(mp[c].size() > 0){
//                             //push the last index to get LSS.
//                             to_delete.push_back(*mp[c].rbegin());
//                             mp[c].pop_back();
//                             break;
//                         }
//                     }
//                 }
//                 // 2.b) if letter
//                 else{
//                     mp[s[i]].push_back(i);
//                 }
//         }
//         //3. Erase all the indexes that are in to_delete 
//         // **starting from the end**  
//         sort(to_delete.begin(), to_delete.end());
//         string ans;
//         for(int i = to_delete.size()-1; i>=0; i--){
//             s.erase(to_delete[i], 1);
//         }
//         return s;
//     }
// };