class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int>mp;
        int sum=0 ,rem=0, cnt=0;
        mp[0]=1;
        for(int i=0;i<(int)nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)==mp.end()) mp[rem]=1;
            else{
                cnt+=mp[rem];
                mp[rem]+=1;
            }
        }
        return cnt;
    }
};