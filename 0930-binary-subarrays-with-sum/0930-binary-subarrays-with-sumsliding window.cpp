class Solution {
public:
    int atmost(vector<int>&nums,int k){
        if(k<0) return 0;
        int l=0,r=0,n=nums.size(),cnt=0,sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};