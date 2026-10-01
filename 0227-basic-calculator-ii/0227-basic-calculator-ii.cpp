using ll=long long;
class Solution {
public:
    int precedence(char c){
        if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        return 0;
    }
    int calculate(string s) {
        stack<char>st;
        string res;
        for(int i=0;i<(int)s.size();i++){
            if(isdigit(s[i])){
                while(i<s.size() && isdigit(s[i])){
                    res+=s[i];
                    i+=1;
                }
                res+=' ';
                i-=1;
            }
            else if(s[i]!=' '){
                while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                    res+=st.top();
                    res+=' ';
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res+=st.top();
            res+=' ';
            st.pop();
        }
        istringstream ss(res);
        string token;
        stack<ll>eval_st;
        while(ss>>token){
            if(token=="+" || token=="-" || token=="/" || token=="*"){
                ll right=eval_st.top(); eval_st.pop();
                ll left=eval_st.top(); eval_st.pop();
                ll op=0;
                if(token=="+") op=left+right;
                else if(token=="-") op=left-right;
                else if(token=="*") op=left*right;
                else if(token=="/") op=left/right;
                eval_st.push(op);
            }
            else eval_st.push(stoll(token));
        }
        return eval_st.top();
    }
};