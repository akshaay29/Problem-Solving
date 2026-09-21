class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        if(n==1) return nums[0];
        int maxi=nums[0] , mini=nums[0] , prod=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(maxi,mini);
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);
            prod=max(prod,maxi);
        }
        return prod;
    }
};