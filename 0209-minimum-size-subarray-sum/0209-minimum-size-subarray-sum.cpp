class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l=0 , r=0 ,minlen=INT_MAX,sum=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                minlen=min(minlen,r-l+1);
                sum-=nums[l];
                l+=1;
            }
        }
        return (minlen==INT_MAX) ? 0:minlen;
    }
};