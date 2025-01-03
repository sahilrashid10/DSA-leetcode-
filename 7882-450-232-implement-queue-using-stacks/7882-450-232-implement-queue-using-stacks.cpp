// class MyQueue {
// public:
//     stack<int>s1,s2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         s1.push(x);
//     }
    
//     int pop() {
//         if(s1.empty())
//             return -1;
//         int i=0;
//         int n = s1.size();
//         while(i<n-1){
//             s2.push(s1.top());
//             s1.pop();
//             i++;
//         }
//         int x = s1.top();
//         s1.pop();
//         i=0;
//         n = s2.size();
//         while(i<n){
//             s1.push(s2.top());
//             s2.pop();
//             i++;
//         }
//         return x;
//     }
    
//     int peek() {
//         if(s1.empty())
//             return -1;
//         int i=0;
//         int n = s1.size();
//         while(i<n){
//             s2.push(s1.top());
//             s1.pop();
//             i++;
//         }
//         int x = s2.top();
//         i=0;
//         n = s2.size();
//         while(i<n){
//             s1.push(s2.top());
//             s2.pop();
//             i++;
//         }
//         return x;
        
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// };

//FOLLOW UP QUESTION
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    // Pop the front element of the queue
    int pop() {
        if (s2.empty()) {
            if (s1.empty()) return -1; // Queue is empty
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    // Get the front element
    int peek() {
        if (s2.empty()) {
            if (s1.empty()) return -1; // Queue is empty
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    // Check if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
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