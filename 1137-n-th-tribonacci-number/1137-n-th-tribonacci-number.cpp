class Solution {
public:
    /*int solve(int n,vector<int>&dp){
        if(n<=1) return n;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    }*/
    int tribonacci(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        /*vector<int>dp(n+1,-1);
        return solve(n,dp);*/
        vector<int>dp(n+1,1);
        dp[0]=0;
        for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        return dp[n];
    }
};