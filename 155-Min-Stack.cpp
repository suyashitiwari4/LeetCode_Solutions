class MinStack {
private:
  stack<int>main;
  stack<int>min;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        main.push(value);
        if(min.empty()||value <= min.top()){
            min.push(value);
        }
        else{
            min.push(min.top());
        }

    }
    
    void pop() {
       main.pop();
       min.pop();

    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */