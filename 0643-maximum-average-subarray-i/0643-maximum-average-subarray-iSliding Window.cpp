class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0 , n=nums.size();
        double sum=0.0;
        for(int r=0;r<k;r++) sum+=nums[r];
        double maxSum=sum;
        for(int r=k;r<n;r++){
            sum-=nums[l++];
            sum+=nums[r];
            maxSum=max(sum,maxSum);
        }
        return maxSum/k;
    }
};