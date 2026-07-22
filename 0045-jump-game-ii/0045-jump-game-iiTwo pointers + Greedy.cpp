class Solution {
public:
    int jump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left=0 , right=0 ,max_jump=0 ,cnt=0;
        while(right<nums.size()-1){
            for(int i=left;i<=right;i++){
                max_jump=max(max_jump,i+nums[i]);
            }
            left=right+1;
            right=max_jump;
            cnt+=1;
        }
        return cnt;
    }
};