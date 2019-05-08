class MinStack {
private:
    list<int> s1; // 存所有数
    list<int> s2; // 只存小数
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    // 入栈
    void push(int x) {
        s1.push_back(x);
        if(s2.empty() || x <= s2.back())
            s2.push_back(x);
    }
    // 出栈
    void pop() {
        if(s1.back() == s2.back())
            s2.pop_back();
        s1.pop_back();
    }
    // 返回栈顶元素
    int top() {
        return s1.back();
    }
    // 返回最小的元素
    int getMin() {
        return s2.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */