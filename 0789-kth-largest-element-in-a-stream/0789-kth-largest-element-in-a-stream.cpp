class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            min_heap.push(num);
            if (min_heap.size() > k)
                min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k)
            min_heap.pop();
        return min_heap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap for top k
    int k;
};
