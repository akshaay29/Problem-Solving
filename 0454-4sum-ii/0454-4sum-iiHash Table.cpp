class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n1=nums1.size(),n2=nums2.size(),n3=nums3.size(),n4=nums4.size() ,cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n3;i++){
            for(int j=0;j<n4;j++){
                mp[nums3[i]+nums4[j]]+=1;
            }
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int target=-(nums1[i]+nums2[j]);
                if(mp.find(target)!=mp.end()) cnt+=mp[target];
            }
        }
        return cnt;
    }
};