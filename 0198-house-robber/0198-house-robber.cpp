class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int inc=nums[i]+solve(i+2,nums,dp);
        int exc=solve(i+1,nums,dp);
        return dp[i]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        vector<int>dp(n,-1);
        int res=solve(0,nums,dp);
        return res;
    }
};