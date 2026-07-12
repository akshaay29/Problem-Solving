class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0,ones=0,twos=0;
        for(int num:nums){
            if(num==0) zeros+=1;
            else if(num==1) ones+=1;
            else twos+=1;
        }
        int i=0;
        while(zeros>0){
            nums[i++]=0;
            zeros-=1;
        }
        while(ones>0){
            nums[i++]=1;
            ones-=1;
        }
        while(twos>0){
            nums[i++]=2;
            twos-=1;
        }
    }
};