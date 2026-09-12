class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(),nums.end());
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
        return res;
    }
};