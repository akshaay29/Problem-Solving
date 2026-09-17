class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tg) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size() , minDiff=INT_MAX ,sum=0;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            int j=i+1  , k=n-1;
            while(j<k){
                int currSum=nums[i]+nums[j]+nums[k];
                if(currSum==tg) return currSum;
                else{
                    if(abs(tg-currSum) < minDiff){
                        minDiff=abs(tg-currSum);
                        sum=currSum;
                    }
                    if(currSum<tg) j+=1;
                    else k-=1;
                }
            }
        }
        return sum;
    }
};