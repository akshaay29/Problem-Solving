class Solution {
public:
    int solve(vector<int>& nums,int i,int limit){
        if(i>limit) return 0;
        int n=nums.size();
        int pick=nums[i]+solve(nums,i+2,limit);
        int notpick=solve(nums,i+1,limit);
        return max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        return max(solve(nums,0,nums.size()-2) , solve(nums,1,nums.size()-1));
    }
};