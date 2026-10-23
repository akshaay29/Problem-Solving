class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int sum=131071;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                flag=true;
                sum&=nums[i];
            }
        }
        if(!flag) return 0;
        return sum;
    }
};