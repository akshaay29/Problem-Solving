class Solution {
public:
    int hIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(),nums.end(),greater<int>());
        int h=0;
        for(int i=0;i<nums.size();i++){
            if((i+1)<=nums[i]) h=i+1;
            else return h;
        }
        return h;
    }
};