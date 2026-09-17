class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(),nums.end());
        int n=nums.size() , cnt=0;
        for(int k=n-1;k>=2;k--){
            int i=0  , j=k-1;
            while(i<j){
                int sum=nums[i]+nums[j];
                if(nums[k]<sum){
                    cnt+=(j-i);
                    j-=1;
                }
                else i+=1;
            }
        }
        return cnt;
    }
};