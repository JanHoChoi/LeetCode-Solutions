class Solution {
public:
    // 迭代法，利用栈
    string decodeString(string s){
        stack<int> s1;
        stack<string> s2;
        int i = 0, size = s.size();
        while(i < size){
            // 如果是数字
            if(s[i] >= '0' && s[i] <= '9'){
                int count = 0;
                while(i<size && s[i] >= '0' && s[i] <= '9'){
                    count *= 10;
                    count += s[i] - '0';
                    i++;
                }
                s1.push(count);
            }
            else if(s[i] == '['){
                s2.push("[");
                i++;
            }
            else if(s[i] == ']'){
                i++;
                string temp = "";
                while(s2.top() != "["){
                    temp = s2.top() + temp;
                    s2.pop();
                }
                s2.pop(); // 把左括號也推出去
                int n = s1.top();
                s1.pop();
                string _temp = "";
                for(int j = 0; j < n; j++){
                    _temp += temp;
                }
                s2.push(_temp);
            }
            else{
                string temp = "";
                while(i<size && s[i] != '[' && s[i] != ']' && !isdigit(s[i])){
                    temp += s[i];
                    i++;
                }
                s2.push(temp);
            }
        }
        string res = "";
        while(!s2.empty()){
            res = s2.top() + res;
            s2.pop();
        }
        return res;
    }

    // 递归法
    string helper(string & s, int & i){
        string res = "";
        int size = s.size();
        while(i < size && s[i] != ']'){
            if(!isdigit(s[i])){
                res += s[i];
                i++;
            }
            else{
                int count = 0;
                if(isdigit(s[i])){
                    while(i < size && isdigit(s[i])){
                        count *= 10;
                        count += s[i] - '0';
                        i++;
                    }
                }
                i++; // 跳过左括号
                string next_s = helper(s,i);
                while(count--){
                    res += next_s;
                }
                i++; // 跳过右括号
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        return helper(s,i);
    }
    
};