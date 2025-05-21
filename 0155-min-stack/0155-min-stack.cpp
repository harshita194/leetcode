class MinStack {
    int *arr;
    int size;
    int topIndex;
    stack<int> minStack;
public:
    MinStack(int size = 100000) {
        this->size = size;
        arr = new int[size];
        topIndex = -1;
    }
    
    void push(int val) {
        if(size - topIndex > 1){
            arr[++topIndex] = val;
            if(minStack.empty() || val <= minStack.top()){
                minStack.push(val);
            }
        }
    }
    
    void pop() {
        if(topIndex >= 0){
            if(arr[topIndex] == minStack.top()){
                minStack.pop();
            }
            topIndex--;
        }
    }
    
    int top() {
        return (topIndex >= 0 && topIndex < size) ? arr[topIndex] : -1;
    }
    
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
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