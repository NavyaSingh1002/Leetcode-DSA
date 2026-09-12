class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else {
            if(val<mini) {
                st.push(2*val-mini);
                mini=val;
            }
            else
                st.push(val);
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        long long top=st.top();
        st.pop();
        if(top<mini)
            mini=2*mini-top;
    }
    
    int top() {
        long long top=st.top();
        if(top<mini)
            return mini;
        return top;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * long long param_3 = obj->top();
 * long long param_4 = obj->getMin();
 */