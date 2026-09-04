class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1 ||  n<=numRows) return s;
        vector<string>mp(numRows);
        int idx=0;
        while(idx<s.size()){
            for(int r=0;r<numRows && idx<s.size();r++) mp[r]+=s[idx++];
            for(int r=numRows-2;r>=1 && idx<s.size();r--) mp[r]+=s[idx++];
        }
        string res="";
        for(auto s:mp) res+=s;
        return res;
    }
};