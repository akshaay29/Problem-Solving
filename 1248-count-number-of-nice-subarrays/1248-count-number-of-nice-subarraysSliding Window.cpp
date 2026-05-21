class Solution {
public:
    int atmost(vector<int>nums,int k){
        int l=0,r=0,n=nums.size(),cnt=0,odd_cnt=0;
        while(r<n){
            if(nums[r]%2!=0) odd_cnt+=1;
            while(odd_cnt>k){
                if(nums[l]%2!=0) odd_cnt-=1;
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};