class Solution {
public:
    int getaverage(vector<int>&nums){
        int n=nums.size(),mid=(n-1)/2;
        sort(nums.begin(),nums.end());
        return nums[mid];
    }
    int minMoves2(vector<int>& nums) {
        int avg=getaverage(nums);
        int cnt=0;
        for(int i:nums) cnt+=abs(i-avg);
        return cnt;
    }
};