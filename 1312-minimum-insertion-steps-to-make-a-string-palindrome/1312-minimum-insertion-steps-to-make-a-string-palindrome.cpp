class Solution {
public:
    int solve(string &s, int left, int right,vector<vector<int>>&dp) {
        if (left > right)
            return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        if (s[left] != s[right])
            return dp[left][right] = 1 + min(solve(s, left, right - 1,dp), solve(s, left + 1, right,dp));
        else return dp[left][right]=solve(s,left+1,right-1,dp);
    }
    int minInsertions(string s) {
        int left = 0, right = s.size() - 1;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s, left, right,dp);
    }
};