class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size() , maxSum=INT_MIN , minSum=INT_MAX , sum=0 , tSum=0;
        tSum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minSum=min(minSum,sum);
            if(sum>0) sum=0;
        }
        return (maxSum<0) ? maxSum:max(maxSum,tSum-minSum);

    }
};