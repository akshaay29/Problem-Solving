class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        vector<vector<int>>after(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    int pf=0;
                    if(buy){
                        pf=max(-prices[i]+after[0][cap] , 0 + after[1][cap]);
                    }
                    else pf=max(prices[i]+after[1][cap-1] , after[0][cap]);
                    curr[buy][cap]=pf;
                }
            }
            after=curr;
        }
        return curr[1][k];
    }
};