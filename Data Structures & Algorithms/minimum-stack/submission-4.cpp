class MinStack {
public:
    stack<int> st;
    stack<int> mst;

    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mst.push(val);
        }
        else {
            st.push(val);
            int m = mst.top();
            if (val < m) mst.push(val);
            else mst.push(m);
        }
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};
