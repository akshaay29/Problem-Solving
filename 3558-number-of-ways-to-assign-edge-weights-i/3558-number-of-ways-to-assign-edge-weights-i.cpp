class Solution {
public:
long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
void dfs(vector<vector<int>>& adj,int &max_depth,int depth,int parent,int node){
    max_depth=max(max_depth,depth);
    for(auto neighbour:adj[node]){
        if(parent!=neighbour){
            dfs(adj,max_depth,depth+1,node,neighbour);
        }
    }
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        int max_depth=0;
        for(auto edge:edges){
            int u=edge[0] , v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,max_depth,0,0,1);
        return power(2,max_depth-1);
    }
};