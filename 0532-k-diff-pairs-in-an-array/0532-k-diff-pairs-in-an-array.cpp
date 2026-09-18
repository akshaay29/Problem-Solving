class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size() , cnt=0;
        if(k<0) return 0;
        unordered_map<int,int>mp;
        for(int i=0;i<(int)nums.size();i++){
            mp[nums[i]]+=1;
        }
        for(auto it:mp){
            if(k==0){ if(it.second>=2) cnt+=1;}
            else{
                if(mp.find(it.first+k)!=mp.end()) cnt+=1;
            }
        }
        return cnt;
    }
};