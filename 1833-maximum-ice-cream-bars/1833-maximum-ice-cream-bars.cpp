class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(int val:costs){
            if(val<=coins) {
                cnt+=1;
                coins-=val;
            }
        }
        return cnt;
    }
};