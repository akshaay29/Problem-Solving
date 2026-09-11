class Solution {
public:
    bool valid(int i,vector<int>dig){
        while(i>0){
            int rem=i%10;
            if(dig[rem]==0) return false;
            i=i/10;
            dig[rem]-=1; 
        }
        return true;
    }
    int totalNumbers(vector<int>& digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>dig(10,0);
        int cnt=0;
        for(int i:digits) dig[i]+=1;
        for(int i=100;i<=998;i+=2){
            if(valid(i,dig)) cnt+=1;
        }
        return cnt;
    }
};