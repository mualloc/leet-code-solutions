class MinStack {
    
public:
    // Base on : https://leetcode.com/problems/min-stack/discuss/49014/Java-accepted-solution-using-one-stack
    MinStack() {
        currMin = INT_MAX;
    }
    
    void push(int val) {
        if(val <= currMin){
            valStack.emplace_back(currMin);  // Old min inserted again before new min
            currMin = val;           
        }
        valStack.emplace_back(val);
    }
    
    void pop() {
        if(top() == currMin){
            valStack.pop_back();
            currMin = valStack.back();      // Retrieve old min value
        }
        valStack.pop_back();            // Remove old min
    }
    
    int top() {
        return valStack.back();
    }
    
    int getMin() {
        return currMin;
    }

private:
    vector<int> valStack;
    int currMin;
  
    
/*public:
    MinStack() {
    }
    
    void push(int val) {
        valStack.push(val);       
        if(0 == minStack.size() || val <= getMin()){  // NOTE '<='
            minStack.push(val);
        }
    }
    
    void pop() {
        int top = valStack.top(); 
        valStack.pop();
        if(top == getMin()){
            minStack.pop(); 
        }
    }
    
    int top() {
        return valStack.top();
    }
    
    int getMin() {
        return minStack.top(); 
    }
private:
    stack<int> valStack;
    stack<int> minStack;*/
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */