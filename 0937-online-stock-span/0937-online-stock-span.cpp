class StockSpanner {
public:
    int index = -1;
    stack<pair<int, int>>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        index++;
        while(!s.empty() && s.top().first <= price)
            s.pop();
        int prevGreater = s.empty() ?  -1 : s.top().second;
        s.push({price, index});

        return index - prevGreater;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


 // class StockSpanner {
// public:
//     stack<int> s;
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         int days = 1;
//         stack<int> stock = s;
//         s.push(price);
//         while(!stock.empty() && stock.top() <= price){
//             stock.pop();
//             days++;
//         }
//         return days;
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */