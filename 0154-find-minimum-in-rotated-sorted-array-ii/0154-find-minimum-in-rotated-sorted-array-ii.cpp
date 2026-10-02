class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l=0,r=nums.size()-1,ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==nums[r]) r-=1;
            else if(nums[mid]<nums[r]) r=mid;
            else l=mid+1;
        }
        return nums[l];
        //return *min_element(nums.begin(),nums.end());
    }
};