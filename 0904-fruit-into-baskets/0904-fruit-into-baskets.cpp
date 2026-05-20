class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,n=fruits.size(),maxlen=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[fruits[r]]+=1;
            while(mp.size()>2){
                mp[fruits[l]]-=1;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l+=1;
            }
            maxlen=max(maxlen,r-l+1);
            r+=1;
        }
        return maxlen;
    }
};