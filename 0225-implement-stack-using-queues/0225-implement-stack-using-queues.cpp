//USING TWO QUEUES
class MyStack {
public:
    queue<int>q1,q2;
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
            return;
        }
        q2.push(x);
        int n = q1.size();
        int i=0;
        while(i<n){
            q2.push(q1.front());
            q1.pop();
            i++;
        }
        swap(q1,q2);
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//FOLLOW UP : USING 1 QUEUE
// class MyStack {
// public:
//     queue<int>q;
//     void push(int x) {
//         q.push(x);
//         int n = q.size();
//         int i = 0;
//         while(i<n-1){
//             q.push(q.front());
//             q.pop();
//             i++;
//         }
//     }
    
//     int pop() {
//         int x = q.front();
//         q.pop();
//         return x;
//     }
    
//     int top() {
//         return q.front();
//     }
    
//     bool empty() {
//         return q.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */