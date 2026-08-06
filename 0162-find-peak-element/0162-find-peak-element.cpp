class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size() , l=0 , r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(mid-1>=0 && mid+1<n && nums[mid] > nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid+1]>nums[mid]) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};