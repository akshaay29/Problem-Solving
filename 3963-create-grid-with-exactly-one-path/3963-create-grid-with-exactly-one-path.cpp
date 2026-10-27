class Solution {
public:
    vector<string> createGrid(int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string>ans;
        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
                if(i==0 || j==n-1) s.push_back('.');
                else s.push_back('#');
            }
            ans.push_back(s);
        }
        return ans;
    }
};