using ll=long long;
class Solution {
public:
    bool isValid(ll mid,vector<int>d,vector<int>r){
        ll both_recharging=floor(mid/lcm(r[0],r[1]));
        ll first_exclusive=floor(mid/r[1])-both_recharging;
        ll second_exclusive=floor(mid/r[0])-both_recharging;
        ll both_free=mid-both_recharging-first_exclusive-second_exclusive;
        ll rem1=max(0ll, d[0]-first_exclusive);
        ll rem2=max(0ll ,d[1]-second_exclusive);
        return (rem1+rem2 <= both_free) ? true:false;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll left=1 , right=2ll*d[0] + 2ll*d[1] , ans=0;
        while(left<=right){
            ll mid=left+(right-left)/2;
            if(isValid(mid,d,r)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};