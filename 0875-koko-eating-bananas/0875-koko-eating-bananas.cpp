using ll=long long;
class Solution {
public:
    bool isValid(vector<int>&piles,  int h,int mid){
        ll cnt=0;
        for(int i=0;i<(int)piles.size();i++){
            ll to_eat=piles[i];
            while(to_eat>mid){
                cnt=cnt+(to_eat/mid);
                to_eat%=mid;
            }
            if(to_eat!=0 && to_eat<=mid) cnt+=1;
        }
        return (cnt<=h) ? true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l=1,r=*max_element(piles.begin(),piles.end()),ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(piles,h,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
   }
};