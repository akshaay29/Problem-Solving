class Solution {
public:
    bool solve(int i,int k,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(k==0) return true;
        if(k<0 || i>=n-1) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        bool pick=solve(i+1,k-nums[i],nums,dp);
        bool notpick=solve(i+1,k,nums,dp);
        return dp[i][k]=(pick || notpick);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0) , n=nums.size();
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>((sum/2)+1,-1));
        return solve(0,sum/2,nums,dp);
    }
};