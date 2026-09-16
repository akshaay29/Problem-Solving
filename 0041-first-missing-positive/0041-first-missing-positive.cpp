class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        for(int i=0;i<n;i++) if(nums[i]<=0) nums[i]=n+1;
        for(int i=0;i<n;i++){
            int j=abs(nums[i]);
            if(j>=1 && j<=n) nums[j-1]=-abs(nums[j-1]);
        }
        for(int i=0;i<n;i++) if(nums[i]>0) return i+1;
        return n+1;
        /**vector<int>res(n+2,-1);
        for(int i=0;i<n;i++){
            int j=nums[i];
            if(j>=0 && j<=n) res[j]=1;
        }
        for(int i=1;i<=n+1;i++) if(res[i]==-1) return i;
        return 0;**/
    }
};