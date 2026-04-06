class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size() , m=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(t[i]==s[j]){
                    ans+=t[i];
                    continue;
                } 
            }
        }
        return (ans==s ? true:false);
    }
};