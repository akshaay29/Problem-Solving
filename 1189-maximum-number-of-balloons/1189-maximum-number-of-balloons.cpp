class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int>mp;
        for(char c:text) mp[c-'a']+=1;
        int cnt=min(min(mp[1],min(mp[0],mp['n'-'a'])),min(mp['l'-'a']/2 , mp['o'-'a']/2));
        return cnt;
    }
};