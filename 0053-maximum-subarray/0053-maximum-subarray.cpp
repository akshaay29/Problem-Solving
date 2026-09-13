class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum=0 , maxSum=INT_MIN;
        for(int i=0;i<(int)nums.size();i++){
            sum+=nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};