class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size() , sum=0  , rem=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            rem=sum%k;
            if(mp.find(rem)==mp.end()) mp[rem]=i;
            else{
                int start=mp[rem];
                if(i-start>=2) return true;
            }
        }
        return false;
    }
};