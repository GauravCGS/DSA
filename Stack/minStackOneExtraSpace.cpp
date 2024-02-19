class MinStack {
public:
    stack<int> s;
    int min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            min = val;
        }else{
            if(val < min){
                int temp = 2*val - min;
                s.push(temp);
                min = val;
            }else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(min > s.top()){
            int new_min = 2*min - s.top();
            min = new_min;
            s.pop();
        }else{
            s.pop();
        }
    }
    
    int top() {
        int top;
        if(min > s.top()){
            top = min;
        }else{
            top = s.top();
        }
        return top;
    }
    
    int getMin() {
        return min;
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
