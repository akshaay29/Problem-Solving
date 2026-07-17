class Solution {
public:
    int getLast(vector<int>&nums,int &target){
        int left=0,right=nums.size()-1,last=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target==nums[mid]){
                last=mid;
                left=mid+1;
            }
            else if(target<nums[mid]) right=mid-1;
            else left=mid+1;
        }
        return last;
    }
    int getFirst(vector<int>&nums,int &target){
        int left=0,right=nums.size()-1,first=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target==nums[mid]){
                first=mid;
                right=mid-1;
            }
            else if(target<nums[mid]) right=mid-1;
            else left=mid+1;
        }
        return first;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int first=getFirst(nums,target) , last=getLast(nums,target);
        return {first,last};
    }
};