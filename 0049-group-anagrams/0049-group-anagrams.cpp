class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<vector<int>,vector<string>>mp;
        for(string s:strs){
            vector<int>freq(26,0);
            for(char c:s) freq[c-'a']+=1;
            mp[freq].push_back(s);
        }
        vector<vector<string>>result;
        for(auto it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};