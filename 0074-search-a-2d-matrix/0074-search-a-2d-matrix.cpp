class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m=nums.size() , n=nums[0].size();
        int l=0 , r=m-1;
        bool ans=false;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target < nums[mid][0]) r=mid-1;
            else if(target > nums[mid][n-1]) l=mid+1;
            else{
                return ans=binary_search(nums[mid].begin() , nums[mid].end(),target);
            }
        }
        return ans;
    }
};