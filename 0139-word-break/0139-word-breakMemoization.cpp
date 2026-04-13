class Solution {
public:
    bool solve(int i, string &s, vector<string>& wordDict,vector<int>&dp){
        if(i==s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        for(auto word:wordDict){
            int n=word.size();
            if(word==s.substr(i,n)){
                if(solve(i+n,s,wordDict,dp)) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
        return solve(0,s,wordDict,dp);
    }
};