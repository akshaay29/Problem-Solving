class Solution {
public:
    bool isValid(int &mid,vector<int> nums,int &days){
        int total_weight=0 , cnt=1;
        for(int i=0;i<nums.size();i++){
            if(total_weight+nums[i] > mid){
                cnt+=1;
                total_weight=0;
            }
            total_weight+=nums[i];
        }
        return (cnt<=days) ? true:false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int left=*max_element(weights.begin(),weights.end()) , right=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(mid,weights,days)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};