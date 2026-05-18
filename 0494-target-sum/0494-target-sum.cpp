class Solution {
public:
    int solve(int i,vector<int>&nums,vector<vector<int>>&dp,int target){
        if(i==nums.size()){
            if(target==0) return 1;
            else return 0;
        }
        if(dp[i][target+2000]!=-1) return dp[i][target+2000];
        int pos=solve(i+1,nums,dp,target-nums[i]);
        int neg=solve(i+1,nums,dp,target+nums[i]);
        return dp[i][target+2000]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(4001,-1));
        return solve(0,nums,dp,target); 
    }
};