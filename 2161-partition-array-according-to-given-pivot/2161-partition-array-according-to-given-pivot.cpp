class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>greater , smaller,equal;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) smaller.push_back(nums[i]);
            else if(nums[i]==pivot) equal.push_back(nums[i]);
            else greater.push_back(nums[i]);
        }
        int i=0,j=0,k=0,l=0;
        while(i<smaller.size()) nums[k++]=smaller[i++];
        while(l<equal.size()) nums[k++]=equal[l++];
        while(j<greater.size()) nums[k++]=greater[j++];
        return nums;
    }
};