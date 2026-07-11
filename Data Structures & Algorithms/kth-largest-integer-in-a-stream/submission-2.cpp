class KthLargest {
    std::priority_queue<int, vector<int>, greater<int>> pq{};
    int _k;
public:
    
    KthLargest(int k, vector<int>& nums) : _k(k) {
        for (int num : nums) 
            insert(num);
    }

    void insert(int num) {
        pq.push(num);
        if (pq.size() > _k) pq.pop();
    }
    
    int add(int num) {
        insert(num);
        
        return pq.top();
    }
};

