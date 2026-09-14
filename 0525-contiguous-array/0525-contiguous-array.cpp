class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size()  , sum=0 ,maxlen=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) sum-=1;
            else sum+=1;
            if(sum==0) maxlen=max(maxlen,i-mp[sum]);
            else if(sum!=0 && mp.find(sum)!=mp.end()) maxlen=max(maxlen,i-mp[sum]);
            else mp[sum]=i;
        }
        return maxlen;
    }
};