class Solution {
public:
    int getsum(int mid,vector<int>&nums){
        int l=0,cnt=0;
        for(int r=0;r<nums.size();r++){
            while(nums[r]-nums[l]>mid){
                l+=1;
            }
            cnt+=r-l;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l=0 , count=0,ans=0;
        int r=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            count=getsum(mid,nums);
            if(count<k) l=mid+1;
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};