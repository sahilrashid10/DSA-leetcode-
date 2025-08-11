//amortised method

class MyQueue {
public:

    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(input.empty() && output.empty())
            return -1;

        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if(input.empty() && output.empty())
            return -1;

        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        return val;
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



//  class MyQueue {
// public:
//     stack<int> s1, s2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         s1.push(x);
//     }
    
//     int pop() {
//         if(s1.empty()) return -1;
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         int val = s2.top();
//         s2.pop();
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//         return val;
//     }
    
//     int peek() {
//         if(s1.empty()) return -1;
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         int val = s2.top();
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//         return val;
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// };
