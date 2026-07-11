class KthLargest {
    vector<int> heap;
    int k;
public:
    KthLargest(int k, const vector<int>& nums) : k(k) {
        for (int num : nums) {
            heap.push_back(num);
            std::make_heap(heap.begin(), heap.end(), std::greater<int>{});
            if (heap.size() > k) {
                heap.erase(heap.begin());
                std::make_heap(heap.begin(), heap.end(), std::greater<int>{});
            }
        }
    }
    
    int add(int val) {
        heap.push_back(val);
        std::make_heap(heap.begin(), heap.end(), std::greater<int>{});
        if (heap.size() > k) {
            heap.erase(heap.begin());
            std::make_heap(heap.begin(), heap.end(), std::greater<int>{});
        }
        

        return heap[0];
    }
};

