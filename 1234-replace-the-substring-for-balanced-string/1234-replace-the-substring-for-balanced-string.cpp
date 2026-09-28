class Solution {
public:
    int balancedString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char,int>mp;
        for(char c:s) mp[c]+=1;
        int l=0,minlen=INT_MAX,k=(int)s.size()/4;
        if(mp['Q']==k && mp['W']==k && mp['E']==k && mp['R']==k) return 0; 
        for(int r=0;r<(int)s.size();r++){
            mp[s[r]]-=1;
            while(mp['Q']<=k && mp['W']<=k && mp['E']<=k && mp['R']<=k){
                minlen=min(minlen,r-l+1);
                mp[s[l]]+=1;
                l+=1;
            }
        }
        return minlen;
    }
};