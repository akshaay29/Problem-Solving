class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[node]=true;
        for(int neighbour=0;neighbour<isConnected.size();neighbour++){
            if(isConnected[node][neighbour]==1 && !visited[neighbour]) dfs(neighbour,isConnected,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        vector<bool>visited(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                provinces+=1;
                dfs(i,isConnected,visited);
            }
        }
        return provinces;
    }
};