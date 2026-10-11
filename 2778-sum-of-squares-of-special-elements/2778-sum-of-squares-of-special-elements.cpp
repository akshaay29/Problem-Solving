class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(n%(i+1)==0) sum+=(nums[i]*nums[i]);
        }
        return sum;
    }
};