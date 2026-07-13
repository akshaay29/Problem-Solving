class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<char,int>mp;
        int left=0 , max_freq=0 , maxlen=0;
        for(int right=0;right<s.size();right++){
            mp[s[right]]+=1;
            max_freq=max(max_freq,mp[s[right]]);
            while((right-left+1) - max_freq > k){
                mp[s[left]]-=1;
                left+=1;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};