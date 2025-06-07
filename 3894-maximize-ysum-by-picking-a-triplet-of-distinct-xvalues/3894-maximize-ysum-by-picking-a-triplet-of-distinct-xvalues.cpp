class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        using node = pair<int, int>;
        int n = y.size();
        priority_queue<node> max_elem;
        
        for(int i=0; i<n; i++){
            max_elem.push({y[i], i});
        }

        int count = 1;
        int prev=-1, pprev=-1;
        int ans = 0;
        while(!max_elem.empty()){
            auto[num, index] = max_elem.top();
            max_elem.pop();
            
            if(count == 1){
                prev = index;
                count++;
                ans += num; 
            }else if(x[prev] != x[index] && count == 2){
                pprev = index;
                count++;
                ans += num; 
            }else if(x[prev] != x[index] && x[pprev] != x[index] && count == 3){
                ans += num;
                count++;
                break;
            }

        }
        if(count != 4)return -1;
        return ans;    
    }
};