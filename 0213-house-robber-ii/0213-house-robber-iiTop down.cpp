class Solution {
public:
    int solve(vector<int>&dp,vector<int>& nums,int i,int limit){
        if(i>limit) return 0;
        if(dp[i]!=-1) return dp[i];
        int n=nums.size();
        int pick=nums[i]+solve(dp,nums,i+2,limit);
        int notpick=solve(dp,nums,i+1,limit);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp1(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1); 
        return max(solve(dp1,nums,0,nums.size()-2) , solve(dp2,nums,1,nums.size()-1));
    }
};