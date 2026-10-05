class Solution {
public:
    int scoreOfParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int>st;
        for(char c:s){
            if(c=='(') st.push(-1);
            else{
                int sum=0;
                while(!st.empty() && st.top()>0){
                    sum+=st.top();
                    st.pop();
                }
                st.pop();
                if(sum==0) st.push(1);
                else st.push(2*sum);
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};