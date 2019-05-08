class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        // 首先清理前后的空格
        while(s[0] == ' ')
            s = s.substr(1);
        while(s[s.size()-1] == ' ')
            s = s.substr(0,s.size()-1);
        int state = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+' || s[i] == '-'){
                if(state == 0) state = 1;
                else if(state == 4) state = 7;
                else return false;
            }
            else if(s[i] == '.'){
                if(state == 0 || state == 1) state = 3;
                else if(state == 2) state = 6;
                else return false;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(state == 2 || state == 6) state = 4;
                else return false;
            }
            else if(isdigit(s[i])){
                if(state == 0 || state == 1 || state == 2) state = 2;
                else if(state == 3 || state == 6) state = 6;
                else if(state == 4 || state == 5 || state == 7) state = 5;
                else return false;
            }
            else return false;
        }
        if(state == 2 || state == 5 || state == 6)
            return true;
        else
            return false;
    }
};