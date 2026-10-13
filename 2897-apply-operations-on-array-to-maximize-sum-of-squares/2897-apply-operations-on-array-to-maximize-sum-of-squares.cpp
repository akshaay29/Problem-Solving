class Solution {
public:
    using ll=long long;
    const int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        int ans=0;
        vector<int>bit_count(31,0);
        for(int num:nums){
            for(int j=0;j<=30;j++){
                if((num&(1LL << j))!=0) bit_count[j]+=1;
            }
        }
        for(int i=0;i<k;i++){
            ll curr=0;
            for(int j=0;j<31;j++){
                if(bit_count[j]>0){
                    curr |= (1ll << j);
                    bit_count[j]-=1;
                }
            }
            ans=(ans+curr*curr)%mod;
        }
        return ans;
    }
};