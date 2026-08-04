class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        int n=nums.size();
        k=k % n;
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.begin()+k);
    }
};