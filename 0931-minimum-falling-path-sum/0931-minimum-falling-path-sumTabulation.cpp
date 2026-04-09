class Solution {
public:
    /*int solve(int i,int j,int n,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d,l = INT_MAX,r = INT_MAX;
        d=matrix[i][j]+solve(i+1,j,n,matrix,dp);
        if(j-1>=0) l=matrix[i][j]+solve(i+1,j-1,n,matrix,dp);
        if(j+1<=n-1) r=matrix[i][j]+solve(i+1,j+1,n,matrix,dp);
        return dp[i][j]=min({d,l,r});
    }*/
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size() , sum=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==n-1) continue;
                int d,l=INT_MAX,r=INT_MAX;
                d=matrix[i][j]+dp[i+1][j];
                if(j-1>=0) l=matrix[i][j]+dp[i+1][j-1];
                if(j+1<n) r=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min({d,l,r});
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};