class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int freq=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target) freq+=1;
                if(2*freq>j-i+1) cnt+=1;
            }
        }
        return cnt;
    }
};