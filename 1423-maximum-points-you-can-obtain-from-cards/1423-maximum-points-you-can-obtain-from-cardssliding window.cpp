class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int curr_sum=0,maxScore=INT_MIN;
        for(int i=0;i<k;i++) {
            curr_sum+=nums[i];
            maxScore=max(maxScore,curr_sum);
        }
        int l=k-1,r=nums.size()-1;
        while(l>=0){
            curr_sum-=nums[l--];
            curr_sum+=nums[r--];
            maxScore=max(maxScore,curr_sum);
        }
        return maxScore;
    }
};