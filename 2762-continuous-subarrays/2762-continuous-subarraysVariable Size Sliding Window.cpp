using ll=long long;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left=0 ;
        ll cnt=0;
        multiset<int>mp;
        for(int right=0;right<nums.size();right++){
            mp.insert(nums[right]);
            while(*mp.rbegin()- *mp.begin() > 2){
                mp.erase(mp.find(nums[left]));
                left+=1;
            }
            cnt+=right-left+1;
        }
        return cnt;
    }
};