class Solution {
public:
    /*int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i==s1.size()) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;
        if(s1[i]==s2[j] ) return 0+solve(i+1,j+1,s1,s2,dp);
        if(dp[i][j]!=-1) return dp[i][j];
        int ins=1+solve(i,j+1,s1,s2,dp);
        int del=1+solve(i+1,j,s1,s2,dp);
        int rep=1+solve(i+1,j+1,s1,s2,dp);
        return dp[i][j]=min({ins,del,rep});
    }*/
    int minDistance(string s1, string s2) {
        int n=s1.size() , m=s2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1,0));
        for(int i=0;i<n;i++) dp[i][m]=n-i;
        for(int j=0;j<m;j++) dp[n][j]=m-j;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]) dp[i][j]=0 + dp[i+1][j+1];
                else {
                    int ins=1+ dp[i][j+1] , del=1 + dp[i+1][j] , rep=1 + dp[i+1][j+1];
                    dp[i][j]=min({ins,del,rep});
                }
            }
        }
        return dp[0][0];
    }
};