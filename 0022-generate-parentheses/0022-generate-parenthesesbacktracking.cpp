class Solution {
public:
    void solve(int n,int open,int close,string &comb,vector<string>&res){
        if(open==0 && close==0){
            res.push_back(comb);
            return;
        }
        if(open>0){
            comb.push_back('(');
            solve(n,open-1,close,comb,res);
            comb.pop_back();
        } 
        if(close>open){
            comb.push_back(')');
            solve(n,open,close-1,comb,res);
            comb.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string comb;
        solve(n,n,n,comb,res);
        return res;
    }
};