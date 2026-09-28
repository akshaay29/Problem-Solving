using ll=long long;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<int>s;
        ll l=0,maxsum=0,sum=0;
        for(int r=0;r<(int)nums.size();r++){
            while(s.find(nums[r])!=s.end()){
                sum-=nums[l];
                s.erase(nums[l++]);    
            }
            sum+=nums[r];
            s.insert(nums[r]);
            while(r-l+1>k){
                sum-=nums[l];
                s.erase(nums[l]);
                l+=1;
            }
            if(r-l+1==k) maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};