class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0, j = 0;
        for(i = 0; i < pushed.size(); i++){
            s.push(pushed[i]); // 第i个元素入栈
            while(j < popped.size() && s.top() == popped[j]){ // 如果符合要求直接出栈
                s.pop();
                j++;
            }
        }
        if(j == popped.size())
            return true;
        else
            return false;
    }
};