class Solution {
public:
    void getdiv(int n,vector<int>&div){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                div.push_back(i);
                if(n/i!=i) div.push_back(n/i);
            }
        }
    }
    int sortableIntegers(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        vector<int>div;
        getdiv(n,div);
        int totalSum=0;
        for(int k:div){
            bool is_valid=true;
            int prev_max=0;
            for(int i=0;i<n;i+=k){
                int curr_min=INT_MAX,curr_max=INT_MIN,cnt=0;
                if(i+k-1<n && nums[i+k-1]>nums[i]) cnt+=1;
                for(int j=i;j<i+k;j++){
                    if(cnt>1){
                        is_valid=false;
                        break;
                    }
                    if(j+1<i+k && nums[j]>nums[j+1]) cnt+=1;
                    curr_min=min(nums[j],curr_min);
                    curr_max=max(nums[j],curr_max);
                }
                if(prev_max>curr_min || cnt>1) is_valid=false;
                prev_max=curr_max;
                if(!is_valid) break;
            }
            if(is_valid) totalSum+=k;
        }
        return totalSum;
    }
};