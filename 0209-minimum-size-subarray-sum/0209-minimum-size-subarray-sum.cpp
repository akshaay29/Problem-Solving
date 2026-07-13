class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left=0 , sum=0;
        int minlen=INT_MAX;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=k){
                minlen=min(minlen,right-left+1);
                sum-=nums[left++];
            }
        }
        return (minlen==INT_MAX) ? 0:minlen;
    }
};