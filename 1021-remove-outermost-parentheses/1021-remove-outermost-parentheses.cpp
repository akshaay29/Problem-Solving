class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string res;
        for(char c:s){
            if(c=='('){
                if(count>0) res.push_back(c);
                count+=1;
            }
            else{
                count-=1;
                if(count>0){
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};