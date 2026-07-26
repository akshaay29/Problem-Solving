class Solution {
public:
    bool solve(int i,int sum,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(sum==target) return true;
        if(sum>target || i==nums.size()) return false;
        if(dp[sum][i]!=-1) return dp[sum][i];
        bool pick=solve(i+1,sum+nums[i],target,nums,dp);
        bool notpick=solve(i+1,sum,target,nums,dp);
        return dp[sum][i]=(pick || notpick);
    }
    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        int totalSum=accumulate(nums.begin(),nums.end(),0) , n=nums.size();
        if(totalSum % 2!=0) return false;
        int target=totalSum/2;
        vector<vector<int>>dp(target+1 , vector<int>(n,-1));
        return solve(0,0,target, nums,dp);
    }
};