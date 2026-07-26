class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&nums,vector<vector<int>>&dp){
        int m=nums.size() , n=nums[0].size();
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=(i+1<m && nums[i+1][j]!=1) ? solve(i+1,j,nums,dp):0;
        int down=(j+1<n && nums[i][j+1]!=1) ? solve(i,j+1,nums,dp):0;
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m=nums.size() , n=nums[0].size();
        if(nums[m-1][n-1]==1 || nums[0][0]==1) return false;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,nums,dp);
    }
};