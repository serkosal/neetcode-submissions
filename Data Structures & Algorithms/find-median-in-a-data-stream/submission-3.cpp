class MedianFinder {
    priority_queue<int, vector<int>, std::less<int>> left;
    priority_queue<int, vector<int>, std::greater<int>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (right.size() && num > right.top())
            right.push(num);
        else
            left.push(num);

        if (int(right.size()) - int(left.size()) > 1) {
            left.push(right.top()); right.pop();
        }
        else if (int(left.size()) - int(right.size()) > 1) {
            right.push(left.top()); left.pop();
        }
    }
        
    double findMedian() {
        if (!left.size() && !right.size()) return 0.0;
        if (left.size() && !right.size()) return left.top();
        if (!left.size() && right.size()) return right.top();

        if (left.size() < right.size()) return right.top();
        if (right.size() < left.size()) return left.top();
        
        return (left.top() + right.top()) / 2.0;
    }
};
