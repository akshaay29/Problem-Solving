class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(nums.size()==1) return {};
        int i=0;
        vector<int>res;
        while(i<(int)nums.size()){
            int x=abs(nums[i]);
            int target_idx=x-1;
            if(nums[target_idx]<0) res.push_back(x);
            else nums[target_idx]=-nums[target_idx];
            i+=1;
        }
        return res;
        /**sort(nums.begin(),nums.end());
        if(nums.size()==1) return {};
        int i=0  , j=i+1;
        vector<int>res;
        while(j<(int)nums.size()){
            if(nums[i]!=nums[j]){
                i=j;
                j+=1;
            }
            else{
                res.push_back(nums[i++]);
                while(j<nums.size() && nums[i]==nums[j]) j+=1;
            }
        }
        return res;**/
    }
};