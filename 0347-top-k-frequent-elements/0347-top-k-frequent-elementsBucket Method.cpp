class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        vector<vector<int>>bucket(n+1);
        vector<int>result;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]+=1;
        for(auto it:mp) bucket[it.second].push_back(it.first);
        for(int i=bucket.size()-1;i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                result.push_back(bucket[i][j]);
                if(result.size()==k) return result;
            }
        }
        return result;
    }
};