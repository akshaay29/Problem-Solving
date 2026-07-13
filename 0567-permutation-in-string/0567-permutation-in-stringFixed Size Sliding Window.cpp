class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<char,int>mp , cnt;
        int left=0;
        for(int right=0;right<s1.size();right++) cnt[s1[right]]+=1;
        for(int right=0;right<s2.size();right++){
            mp[s2[right]]+=1;
            while(right-left+1 > s1.size()){
                mp[s2[left]]-=1;
                if(mp[s2[left]]==0) mp.erase(s2[left]);
                left+=1;
            }
            if(cnt==mp) return true;
        }
        return false;
    }
};