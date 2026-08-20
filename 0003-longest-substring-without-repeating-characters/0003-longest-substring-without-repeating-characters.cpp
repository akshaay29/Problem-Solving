class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<int>st;
        int l=0,maxlen=0,cnt=0;
        for(int r=0;r<(int)s.size();r++){
            cnt+=1;
            st.insert(s[r]);
            while(st.size()!=cnt){
                cnt-=1;
                st.erase(s[l++]);
                st.insert(s[r]);
            }
            maxlen=max(cnt,maxlen);
        }
        return maxlen;
    }
};