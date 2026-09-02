class Solution {
public:
    int solve(int i,int j,string &s){
        if(i==j) return 1;
        if(j==i+1 && s[i]==s[j]) return 1;
        if(s[i]==s[j] && solve(i+1,j-1,s)==1) return 1;
        return 0;
    }
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int start=0,n=s.size() , maxlen=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)){
                    if(j-i+1 > maxlen){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};