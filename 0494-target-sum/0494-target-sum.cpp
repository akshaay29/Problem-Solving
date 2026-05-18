class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(4001,0));
        dp[nums.size()][2000]=1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<=4000;j++){
                int pos=(j-nums[i]>=0) ? dp[i+1][j-nums[i]]:0;
                int neg=(j+nums[i]<=4000) ? dp[i+1][j+nums[i]]:0;
                dp[i][j]=pos+neg;
            }
        }
        return dp[0][target+2000];
    }
};