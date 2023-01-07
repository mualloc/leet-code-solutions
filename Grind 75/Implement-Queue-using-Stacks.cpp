class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stackNewestAtTop.push(x);
    }
    
    int pop() {
        int result = peek();
        stackOldestAtTop.pop();
        return result;
        
        /*int result;
        while(false == stack1.empty()){
            int x = stack1.top();
            stack2.push(x);
            stack1.pop();
        }
        result = stack2.top();
        stack2.pop();
        while(false == stack2.empty()){
            int x = stack2.top();
            stack1.push(x);
            stack2.pop();
        }
        return result;*/
    }
    
    int peek() {
        shiftElemets();
        int result = stackOldestAtTop.top();
        return result;
        /*while(false == stack1.empty()){
            int x = stack1.top();
            stack2.push(x);
            stack1.pop();
        }
        result = stack2.top();
        while(false == stack2.empty()){
            int x = stack2.top();
            stack1.push(x);
            stack2.pop();
        }
        return result;*/
    }
    
    bool empty() {
        return stackNewestAtTop.empty() && stackOldestAtTop.empty();
    }
    
private:
    void shiftElemets(){
        if(stackOldestAtTop.empty()){
            while(false == stackNewestAtTop.empty()){
                int x = stackNewestAtTop.top(); stackNewestAtTop.pop();
                stackOldestAtTop.push(x);
            }
        }
    }
    stack<int> stackNewestAtTop;  
    stack<int> stackOldestAtTop;  
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */