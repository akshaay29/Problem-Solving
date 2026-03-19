class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        unordered_map<int,list<int>>adj;
        for(auto it:prerequisites){
            int u=it[1] , v=it[0];
            adj[u].push_back(v);
            indegree[v]+=1;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto neighbour:adj[front]){
                indegree[neighbour]-=1;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return (ans.size()!=numCourses) ? vector<int>{}:ans;
    }
};