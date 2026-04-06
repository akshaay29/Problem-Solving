class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size() , m=s.size();
        int i=0,j=0;
        while(j<n){
            if(i<m && s[i]==t[j]){
                i+=1;
                j+=1;
            }
            else j+=1;
        }
        return (i==m ? true:false);
    }
};