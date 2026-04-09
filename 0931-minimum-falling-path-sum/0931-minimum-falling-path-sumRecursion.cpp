class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>&matrix){
        if(i==n-1) return matrix[i][j];
        int d,l = INT_MAX,r = INT_MAX;
        d=matrix[i][j]+solve(i+1,j,n,matrix);
        if(j-1>=0) l=matrix[i][j]+solve(i+1,j-1,n,matrix);
        if(j+1<=n-1) r=matrix[i][j]+solve(i+1,j+1,n,matrix);
        return min({d,l,r});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size() , sum=INT_MAX;
        for(int j=0;j<n;j++) sum=min(sum,solve(0,j,n,matrix));
        return sum;
    }
};