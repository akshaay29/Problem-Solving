class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size(),maxlen=0 , maxfreq=INT_MIN;
        unordered_map<int,int>mp;
        while(r<n){
            mp[s[r]-'A']+=1;
            maxfreq=max(maxfreq,mp[s[r]-'A']);
            int changes_needed=(r-l+1)-maxfreq;
            if(changes_needed>k){
                mp[s[l]-'A']-=1;
                if(mp[s[l]-'A']==0) mp.erase(s[l]-'A');
                l+=1;
            }
            maxlen=max(maxlen,r-l+1);
            r+=1;
        }
        return maxlen;
    }
};