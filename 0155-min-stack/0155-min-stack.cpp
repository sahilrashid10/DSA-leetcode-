class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
            s.push({val, val});
        else
            s.push({val, min(val, s.top().second)});
    }
    
    void pop() {
        s.pop();
     }
    
    int top() {
        if(s.empty()) return INT_MAX;

        return s.top().first;
    }
    
    int getMin() {
        if(s.empty()) return INT_MAX;

        return s.top().second;
    }
};

/**
 * Your MiniStack object will be instantiated and called as such:
 * MiniStack* obj = new MiniStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMini();
 */


//  class MiniStack {
// public:
//     stack<pair<int, int>> miniStack;
//     stack<pair<int, int>> bufferStack;
//     int index = 0;
//     MiniStack() {
        
//     }
    
//     void push(int val) {
//         index++;
//         if(miniStack.empty())
//             miniStack.push({val, index});

//         else if(miniStack.top().first >= val)
//             miniStack.push({val, index});

//         else
//             bufferStack.push({val, index});
        
//     }
    
//     void pop() {
        
//         if(!miniStack.empty() && !bufferStack.empty()){
//             if(miniStack.top().second > bufferStack.top().second)
//                 miniStack.pop();
//             else 
//                 bufferStack.pop();
//         }else if(!miniStack.empty())
//             miniStack.pop();
//     }
    
//     int top() {
//         if(!miniStack.empty() && !bufferStack.empty()){

//             if(miniStack.top().second > bufferStack.top().second)
//                 return miniStack.top().first;

//             else 
//                 return bufferStack.top().first;
//         }else if(!miniStack.empty())
//             return miniStack.top().first;

//     return -1;
        
//     }
    
//     int getMini() {
//         if(miniStack.empty()) return -1;

//         int mini = miniStack.top().first;
//         return mini;
//     }
// };

// /**
//  * Your MiniStack object will be instantiated and called as such:
//  * MiniStack* obj = new MiniStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMini();
//  */