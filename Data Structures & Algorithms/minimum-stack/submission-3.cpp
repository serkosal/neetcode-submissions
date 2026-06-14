class MinStack {
public:
    vector<int> arr;
    int min = std::numeric_limits<int>::max();

    MinStack() {
        
    }
    
    void push(int val) {
        if (val < min) min = val;
        arr.push_back(val);
    }
    
    void pop() {
        arr.pop_back();

        if (arr.size())
            min = *std::min_element(arr.begin(), arr.end());
        else min = std::numeric_limits<int>::max();
    }
    
    int top() {
        return arr.back(); 
    }
    
    int getMin() {
        return min;
    }
};
