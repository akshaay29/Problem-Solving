const int mod=1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long even=1,odd=0,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0) even+=1;
            else odd+=1;
        }
        return (odd*even)%mod;
    }
};