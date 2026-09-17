class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size() , i=0,  j=n-1 , cnt=0;
        sort(nums.begin(),nums.end());
        while(i<=j){
            if(nums[i]+nums[j]<=limit) i+=1;
            j-=1;
            cnt+=1;
        }
        return cnt;
    }
};