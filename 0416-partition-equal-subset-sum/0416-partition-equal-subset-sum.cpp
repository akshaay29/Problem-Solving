class Solution {
public:
    bool solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool pick=false;
        if(target>=nums[i]) pick=solve(i+1,target-nums[i],nums,dp);
        bool notpick=solve(i+1,target,nums,dp);
        return dp[i][target]=(pick || notpick);
    }
    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int total_sum=accumulate(nums.begin(),nums.end(),0)  , n=nums.size();
        if(total_sum%2!=0)return false;
        int target=total_sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,target,nums,dp);
    }
};