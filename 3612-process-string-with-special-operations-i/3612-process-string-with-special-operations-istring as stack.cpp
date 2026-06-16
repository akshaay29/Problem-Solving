class Solution {
public:
    string processStr(string s) {
       string result="";
       for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z') result+=s[i];
        else if(result.size()!=0 && s[i]=='*') result.pop_back();
        else if(result.size()!=0 && s[i]=='#') result+=result;
        else if(result.size()!=0 && s[i]=='%') reverse(result.begin(),result.end());
       } 
       return result;
    }
};