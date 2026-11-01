class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt=0 , mini=*min_element(nums.begin(),nums.end());
        for(int i:nums){
            cnt+=i-mini;
        }
        return cnt;
    }
};