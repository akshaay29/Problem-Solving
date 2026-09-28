class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l=0,total=0,extra=0,maxcus=0;
        for(int i=0;i<(int)customers.size();i++){
            if(grumpy[i]==0) total+=customers[i];
        }
        for(int r=0;r<(int)grumpy.size();r++){
            if(grumpy[r]==1) extra+=customers[r];
            while(r-l+1>k){
                if(grumpy[l]==1) extra-=customers[l];
                l+=1;
            }
            maxcus=max(maxcus,extra);
        }
        return maxcus+total;
    }
};