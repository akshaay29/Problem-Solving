class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i=0,j=0 ,n1=nums1.size() ,n2=nums2.size()  , maxDist=0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                maxDist=max(maxDist,j-i);
                j+=1;
            }
            else i+=1;
        }
        return maxDist;
    }
};