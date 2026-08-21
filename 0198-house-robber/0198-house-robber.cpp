class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+solve(i-2,nums,dp);
        int notpick=solve(i-1,nums,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size() , i=n-1;
        vector<int>dp(n+1,-1);
        return solve(i,nums,dp);
    }
};