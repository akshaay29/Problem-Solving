class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0 ,  j=0 , cnt=0;
        while(i<g.size() && j<s.size()){
            if(g[i]>s[j]) j+=1;
            else {
                cnt+=1;
                i+=1;
                j+=1;
            }
        }
        return cnt;
    }
};