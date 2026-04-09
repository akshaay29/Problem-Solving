class Solution {
public:
    /*bool solve(int i,int k,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(k==0) return true;
        if(k<0 || i>=n-1) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        bool pick=solve(i+1,k-nums[i],nums,dp);
        bool notpick=solve(i+1,k,nums,dp);
        return dp[i][k]=(pick || notpick);
    }*/
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0) , n=nums.size();
        if(sum%2!=0) return false;
        int k=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=k;j>=0;j--){
                bool pick=false;
                if(j-nums[i]>=0) pick=dp[i+1][j-nums[i]];
                bool notpick=dp[i+1][j];
                dp[i][j]=(pick || notpick);
            }
        }
        return dp[0][k];
    }
};