//vector
class MyQueue {
public:
    vector<int> v;
    MyQueue() {
    }
    
    void push(int x) {
        v.emplace_back(x);
    }
    
    int pop() {
        int t=v[0];
        v.erase(v.begin());
        return t;
    }
    
    int peek() {
        return v[0];
    }
    
    bool empty() {
        return v.size()==0;
    }
};

//two stack
class MyQueue {
public:
    stack<int> first;
    stack<int> second;
    MyQueue() {
        
    }
    
    void push(int x) {  
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
        first.push(x);
        while(!second.empty()){
            first.push(second.top());
            second.pop();
        }
    }
    
    int pop() {
        int i=first.top();
        first.pop();
        return i;
    }
    
    int peek() {
        return first.top();
    }
    
    bool empty() {
        return first.empty();
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
