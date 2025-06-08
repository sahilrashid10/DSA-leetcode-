class Solution {
public:

    void solve(vector<int> &result, int &n, int num){
        if(num > n) return;

        result.push_back(num);

        for(int i=0; i<=9; i++){
            int newNum = num*10 + i;
            if(newNum > n)  return;
            solve(result, n, newNum);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1; i<=9; i++){
            solve(result, n, i);
        }
        return result;
    }
};