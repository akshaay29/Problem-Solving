using ll=long long;
class Solution {
public:
    bool isValid(int m,vector<ll>&diff,ll k){
        ll need=0;
        for(int i=diff.size()-1;i>=0;i--){
            if(diff[i]>=m){
                need+=diff[i]-m;
            }
            if(need>k) return false;
        }
        return true;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll n=nums1.size();
        vector<ll>diff(n,0);
        for(int i=0;i<n;i++) diff[i]=abs(nums1[i]-nums2[i]);
        sort(diff.begin(),diff.end());
        ll l=0,r=diff[n-1],ans=0,count=0,rem_k=0,used_k=0 , k=k1+k2;
        while(l<=r){
            int m=l+(r-l)/2;
            if(isValid(m,diff,k)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        for(int i=0;i<n;i++){
            if(diff[i]>=ans){
                used_k+=diff[i]-ans;
                count+=1;
            }
        }
        if(ans==0) return 0;
        rem_k=k-used_k;
        ll sum= (rem_k*(ans-1)*(ans-1)) + ((count-rem_k)*ans*ans);
        for(int i=0;i<n;i++){
            if(diff[i]<ans) sum+=diff[i]*diff[i];
        }
        return sum;
    }
};