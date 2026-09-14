class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size() , rem=0 , comp=0 , cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            rem=nums[i]%60;
            comp=(60-rem)%60;
            if(mp.find(comp)==mp.end()) mp[rem]+=1;
            else{
                cnt+=mp[comp];
                mp[rem]+=1;
            }
        }
        return cnt;
    }
};