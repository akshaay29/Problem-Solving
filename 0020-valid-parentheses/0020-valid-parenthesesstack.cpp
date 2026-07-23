class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int>st;
        if(s.size()==1) return false;
        for(char c:s){
            if(c=='(' || c=='[' || c=='{') st.push(c);
            else{
                if(st.empty()) return false; 
                if((c==')' && st.top()!='(') || (c==']' && st.top()!='[')|| (c=='}' && st.top()!='{')) return false;
                st.pop();
            }
        }
        return (st.empty()) ? true:false ;
    }
};