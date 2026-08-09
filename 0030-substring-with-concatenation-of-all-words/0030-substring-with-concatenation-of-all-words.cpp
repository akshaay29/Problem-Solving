class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string,int>mp;
        vector<int>res;
        int wordlen=words[0].size();
        if (s.size() < words.size() * wordlen) return res;
        for(string word:words) mp[word]+=1;
        for(int i=0;i<wordlen;i++){
            int cnt=0 , l=i;
            unordered_map<string,int>seen;
        for(int r=i;r<s.size()-wordlen+1;r+=wordlen){
            string sub=s.substr(r,wordlen);
            if(mp.find(sub)==mp.end()){
                seen.clear();
                cnt=0;
                l=wordlen+r;
                continue;
            }
            cnt+=1;
            seen[sub]+=1;
            while(seen[sub]>mp[sub]){
                string leftword=s.substr(l,wordlen);
                seen[leftword]-=1;
                cnt-=1;
                l+=wordlen;
            }
            if(cnt==words.size()) res.push_back(l);
        }
        }
        return res;
    }
};