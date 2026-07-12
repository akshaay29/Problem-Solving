class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(),nums.end());
        int i=0 , j=nums.size()-1;
        float avg=INT_MAX;
        while(i<j){
            float compute=(float)((nums[i++]+nums[j--])/2.0);
            avg=min(avg,compute);
        }
        return avg;
    }
};