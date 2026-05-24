class Solution {
public:
    int solve(vector<int>&nums,vector<int>&dp,int i,int d){
        int max_jumps=0,n=nums.size();
        if(dp[i]!=-1) return dp[i];
        for(int j=i+1;j<=min(i+d,n-1);j++){
            if(nums[j]>=nums[i]) break;
            max_jumps=max(max_jumps,1+solve(nums,dp,j,d));
        }
        for(int j=i-1;j>=max(i-d,0);j--){
            if(nums[j]>=nums[i]) break;
            max_jumps=max(max_jumps,1+solve(nums,dp,j,d));
        }
        return dp[i]=max_jumps;
    }
    int maxJumps(vector<int>& nums, int d) {
        int max_jumps=0;
        vector<int>dp(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++) max_jumps=max(max_jumps,1+solve(nums,dp,i,d));
        return max_jumps;
    }
};