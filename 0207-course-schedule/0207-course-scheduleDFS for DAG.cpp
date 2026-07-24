class Solution {
public:
    bool dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adj){
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]) {
                if(dfs(neighbour,visited,dfsvisited,adj)) return true;
            }
            else if(dfsvisited[neighbour]) return true;
        }
        dfsvisited[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,list<int>>adj;
        for(auto it:nums){
            int u=it[1] , v=it[0];
            adj[u].push_back(v);
        }
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsvisited;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]) if(dfs(i,visited,dfsvisited,adj)) return false;
        }
        return true;
    }
};