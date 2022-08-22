class MinStack {
public:
    stack<int>s;
    stack<int>as;
    // priority_queue<int,vector<int>,greater<int>>q;
    MinStack() {
        // stack<int>s;
        s.push(NULL);   
    }
    
    void push(int val) {
        s.push(val);
        if(as.empty() or val<=as.top())
            as.push(val);
    }
    
    void pop() {
        if(as.top()==s.top())
            as.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return as.top();
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */