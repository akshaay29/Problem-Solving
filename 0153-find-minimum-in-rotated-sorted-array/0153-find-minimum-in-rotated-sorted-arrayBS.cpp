class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left=0 , right=nums.size()-1 , ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[ans]) ans=mid;
            if(nums[right]<nums[mid]) left=mid+1;
            else right=mid-1;
        }
        return nums[ans];
    }
};