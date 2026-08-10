class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(s.size()<t.size()) return "";
        unordered_map<int,int>mp,cnt;
        for(char c:t) mp[c]+=1;
        int l=0 , need=mp.size() , have=0,minlen=INT_MAX, start=-1;
        for(int r=0;r<(int)s.size();r++){
            cnt[s[r]]+=1;
            if(mp.find(s[r])!=mp.end() && mp[s[r]]==cnt[s[r]]) have+=1;
            while(have==need){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    start=l;
                }
                cnt[s[l]]-=1;
                if(mp.find(s[l])!=mp.end() && mp[s[l]]>cnt[s[l]]) have-=1;
                l+=1;
            }
        }
        return (start==-1 || minlen==INT_MAX) ? "":s.substr(start,minlen);
    }
};