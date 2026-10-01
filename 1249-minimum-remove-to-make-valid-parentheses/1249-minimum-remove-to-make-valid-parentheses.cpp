class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string res="";
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='(') st.push(i);
            else if(c==')'){
                if(!st.empty()) st.pop();
                else s[i]='*';
            }
        }
        while(!st.empty()){
            s[st.top()]='*'; st.pop();
        } 
        for(char c:s) if(c!='*') res+=c;
        return res;
    }
};