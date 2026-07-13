using ll=long long;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left=0 , cnt=0 , maxCnt=0;
        unordered_set<int>st;
        for(int right=0;right<s.size();right++){
            cnt+=1;
            st.insert(s[right]);
            while(st.size()!=cnt){
                cnt-=1;
                st.erase(s[left++]);
                st.insert(s[right]);
            }
            maxCnt=max(maxCnt,cnt);
        }
        return maxCnt;
    }
};