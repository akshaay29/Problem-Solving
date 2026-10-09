class Solution {
public:
    int minInsertions(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int open=0  , ans=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='(') open+=1;
            else{
                if(i+1<s.size() && s[i+1]==')') i+=1;
                else ans+=1;

                if(open>0) open-=1;
                else ans+=1;
            }
        }
        return  ans+open*2;
    }
};