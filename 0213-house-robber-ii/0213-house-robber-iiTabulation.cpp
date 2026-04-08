class Solution {
public:
    /*int solve(vector<int>&dp,vector<int>& nums,int i,int limit){
        if(i>limit) return 0;
        if(dp[i]!=-1) return dp[i];
        int n=nums.size();
        int pick=nums[i]+solve(dp,nums,i+2,limit);
        int notpick=solve(dp,nums,i+1,limit);
        return dp[i]=max(pick,notpick);
    }*/
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(nums.size()+2,0);
        vector<int>dp2(nums.size()+2,0); 
        for(int i=n-2;i>=0;i--){
            int pick=nums[i]+dp1[i+2];
            int notpick=dp1[i+1];
            dp1[i]=max(pick,notpick);
        }
        for(int i=n-1;i>=1;i--){
            int pick=nums[i]+dp2[i+2];
            int notpick=dp2[i+1];
            dp2[i]=max(pick,notpick);
        }
        return max(dp1[0],dp2[1]);
    }
};