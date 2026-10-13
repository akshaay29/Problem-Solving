class Solution {
public:
    using ll=long long;
    long long maxAlternatingSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll ans=0;
        for(int i=0;i<nums.size();i++) nums[i]=nums[i]*nums[i];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()/2) ans-=nums[i];
            else ans+=nums[i];
        }
        return ans;
    }
};