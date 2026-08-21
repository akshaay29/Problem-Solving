class Solution {
public:
    /*int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+solve(i-2,nums,dp);
        int notpick=solve(i-1,nums,dp);
        return dp[i]=max(pick,notpick);
    }*/
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        /*vector<int>dp(n+1,-1);
        return solve(i,nums,dp);*/
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2] , dp[i-1]);
        }
        return dp[n-1];
    }
};