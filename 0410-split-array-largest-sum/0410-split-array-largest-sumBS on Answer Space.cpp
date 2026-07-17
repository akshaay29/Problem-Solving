class Solution {
public:
    bool isValid(int mid,vector<int>nums,int k){
        int sum=0 , cnt=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i] > mid){
                cnt+=1;
                sum=0;
            }
            sum+=nums[i];
        }
        return (cnt<=k) ? true:false;

    }
    int splitArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left=*max_element(nums.begin(),nums.end()) , right=accumulate(nums.begin(),nums.end(),0),ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(mid,nums,k)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};