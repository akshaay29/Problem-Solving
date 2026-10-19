using ll=long long;
const int MOD=1e9+7;
class Solution {
public:
    void compute(int n,vector<vector<ll>>&comb){
        for(int i=0;i<=n;i++){
            comb[i][0]=1;
            for(int j=1;j<=i;j++){
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
            }
        }
    }
    ll solve(vector<int>&nums,vector<vector<ll>>&comb){
        int n=nums.size();
        if(n<3) return 1;
        int root=nums[0];
        vector<int>left,right;
        for(auto num:nums){
            if(num>root) right.push_back(num);
            else if(num<root) left.push_back(num);
        }
        ll l=left.size()   ,  r=right.size();
        ll lways=(solve(left,comb)+MOD)%MOD; ll rways=(solve(right,comb)+MOD)%MOD;
        ll total=(((lways*rways)%MOD)*(comb[l+r][l]+MOD)%MOD)%MOD;
        return total%MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>>comb(n+1,vector<ll>(n+1,0));
        compute(n,comb);
        return solve(nums,comb)-1;
    }
};