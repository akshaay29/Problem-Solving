class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            int u=it[1] , v=it[0];
            adj[u].push_back(v);
            indegree[v]+=1;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++) if(indegree[i]==0) q.push(i);
        int cnt=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cnt+=1;
            for(auto neighbour:adj[front]){
                indegree[neighbour]-=1;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return (cnt==numCourses) ? true:false;
    }
};