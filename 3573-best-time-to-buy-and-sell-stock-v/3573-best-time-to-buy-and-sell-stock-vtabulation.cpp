using ll=long long;
const long long c=LLONG_MIN/2;
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        ll n=prices.size();
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(3,vector<ll>(k+1,c)));
        for(int cap=0;cap<=k;cap++) dp[n][0][cap]=0;
        for(int i=0;i<=n;i++) dp[i][0][0]=0;
        for(ll i=n-1;i>=0;i--){
            for(ll state=0;state<=2;state++){
                for(ll cap=1;cap<=k;cap++){
                    ll pf=0;
                    if(state==0){
                        pf=max({prices[i]+dp[i+1][2][cap] , -prices[i]+dp[i+1][1][cap] , dp[i+1][0][cap]});
                    }
                    else if(state==1){
                        pf=max({prices[i]+dp[i+1][0][cap-1] , dp[i+1][1][cap]});
                    }
                    else{
                        pf=max({-prices[i]+dp[i+1][0][cap-1],dp[i+1][2][cap]});
                    }
                    dp[i][state][cap]=pf;
                }
            }
        }
        return dp[0][0][k];
    }
};