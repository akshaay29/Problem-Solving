class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0 , max_len=0;
        unordered_map<char,int>mp;
        for(int right=0;right<s.size();right++){
            mp[s[right]]+=1;
            while(mp[s[right]]>2){
                mp[s[left]]-=1;
                left+=1;
            }
            max_len=max(max_len,right-left+1);
        }
        return max_len;
    }
};