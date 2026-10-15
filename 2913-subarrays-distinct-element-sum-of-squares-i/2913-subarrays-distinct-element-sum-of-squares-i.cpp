class Solution {
public:
    int sumCounts(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>s;
            for(int j=i;j<nums.size();j++){
                s.insert(nums[j]);
                cnt+=(s.size()*s.size());
            }
        }
        return cnt;
    }
};