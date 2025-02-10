class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequencies of each element
        unordered_map<int, int> freq;
        for (int& num : nums) {
            freq[num]++;
        }

        // Step 2: Maintain a min-heap of size k
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (auto& [num, count] : freq) { // Structured binding for clarity
            minHeap.push({count, num});  // Push (frequency, number) into the heap
            if (minHeap.size() > k) {
                minHeap.pop(); // Keep only the top k elements
            }
        }

        // Step 3: Extract elements from the heap into the result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second); // Get the number
            minHeap.pop();
        }

        return result;
    }
};
