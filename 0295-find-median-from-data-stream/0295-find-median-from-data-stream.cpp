class MedianFinder {
public:
    // max_heap to store the smaller half
    priority_queue<int> max_heap;
    // min_heap to store the larger half
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder() {}

    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        // Balance the heaps sizes so that max_heap can have at most one extra element
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        int totalSize = max_heap.size() + min_heap.size();
        if (totalSize % 2 == 0) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }
};
