class Solution {
public:
    int solve(vector<int>&nums,vector<vector<int>>&dp,int buy,int i,int pf){
        if(i==nums.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            pf+=max(solve(nums,dp,1,i+1,pf) , -nums[i]+solve(nums,dp,0,i+1,pf));
        }
        else pf+=max(solve(nums,dp,0,i+1,pf) , nums[i]+solve(nums,dp,1,i+1,pf));
        return dp[i][buy]=pf;
    }
    int maxProfit(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max_pf=0 , n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(nums,dp,1,0,max_pf);  
    }
};