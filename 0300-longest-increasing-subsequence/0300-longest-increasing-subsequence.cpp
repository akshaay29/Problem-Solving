class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=0;i<(int)nums.size();i++){
            if(temp.back()<nums[i]) temp.push_back(nums[i]);
            else{
                int lb=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[lb]=nums[i];
            }
        }
        return temp.size();
    }
};