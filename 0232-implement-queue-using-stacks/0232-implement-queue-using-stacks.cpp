class MyQueue {
private:
    std::stack<int> front;
    std::stack<int> back;
    
public:
    MyQueue() {
    }
    
    void push(int x) {
        front.push(x);
    }
    
    int pop() {
        if (back.empty()) {
            transfer();
        }
        
        int res = back.top();
        back.pop();
        return res;
    }
    
    int peek() {
        if (back.empty()) {
            transfer();
        }
        return back.top();
    }
    
    bool empty() {
        return front.empty() && back.empty();
    }
private:
    void transfer() {
        while(!front.empty()) {
            back.emplace(front.top());
            front.pop();
        }
    }
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */