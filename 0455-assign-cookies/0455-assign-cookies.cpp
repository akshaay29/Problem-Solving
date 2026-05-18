class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0) return 0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<=g.size()-1 && j<=s.size()-1){
            if(g[i]>s[j]) j++;
            else {
                i++;
                j++;
            }
        }
        return i;
    }
};