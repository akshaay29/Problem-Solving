class Solution {
public:
    void solve(int start,int l,int r,string s,vector<string>&result){
        if(l==0 && r==0){
            if(isValid(s)) result.push_back(s);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(i>start && s[i]==s[i-1]) continue;
            if(s[i]=='(' && l>0) solve(i,l-1,r,s.substr(0,i)+s.substr(i+1),result);
            else if(s[i]==')' && r>0) solve(i,l,r-1,s.substr(0,i)+s.substr(i+1),result);
        }

    }
    bool isValid(string s){
        int cnt=0;
        for(char c:s){
            if(c=='(') cnt+=1;
            else if(c==')') cnt-=1;
            if(cnt<0) return false;
        }
        return (cnt==0 ? true:false);
    }
    vector<string> removeInvalidParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string>result;
        int l=0,r=0;
        for(char c:s){
            if(c=='(') l+=1;
            else if(c==')'){
                if(l>0) l-=1;
                else r+=1;
            }
        }
        solve(0,l,r,s,result);
        return result;
    }
};