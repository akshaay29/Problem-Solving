class Solution {
public:
    string simplifyPath(string path) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<string>st;
        stringstream ss(path);
        string token,res="";
        while(getline(ss,token,'/')){
            if(token=="." || token=="") continue;
            else if(token==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(token);
        }
        while(!st.empty()){
            res="/"+st.top()+res; st.pop();
        }
        return (res=="") ? "/":res;
    }
};