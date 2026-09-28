class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt=0,l=0,maxlen=0;
        for(int r=0;r<(int)nums.size();r++){
            if(nums[r]==0) cnt+=1;
            while(cnt>1){
                if(nums[l]==0) cnt-=1;    
                l+=1;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen-1;
    }
};