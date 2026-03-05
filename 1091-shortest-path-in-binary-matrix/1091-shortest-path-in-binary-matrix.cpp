class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1; 
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({1,{0,0}});
        vis[0][0]=1;
        int delrow[8]={-1,-1,-1,0,1,1,1,0};
        int delcol[8]={-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int dist=q.front().first;
            q.pop();
            if(row==n-1 && col==n-1) return dist;
            for(int i=0;i<8;i++){
                int newr=row+delrow[i] , newc=col+delcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && vis[newr][newc]==0){
                    vis[newr][newc]=1;
                    q.push({dist+1,{newr,newc}});
                }
            }
        }
        return -1;
    }
};