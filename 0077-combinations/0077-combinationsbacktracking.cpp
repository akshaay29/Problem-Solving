class Solution {
public:
    void solve(vector<vector<int>>&res , vector<int>&comb,int n,int k, int idx){
        if(comb.size()==k) res.push_back(comb);
        for(int i=idx;i<=n;i++){
            comb.push_back(i);
            solve(res,comb,n,k,i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>comb;
        vector<vector<int>>res;
        solve(res,comb,n,k,1);
        return res;
    }
};