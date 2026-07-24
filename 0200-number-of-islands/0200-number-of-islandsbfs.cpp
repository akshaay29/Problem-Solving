class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>&grid,vector<vector<bool>>&visited){
        int m=grid.size() , n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c]=true;
        while(!q.empty()){
            int n1=q.size();
            for(int i=0;i<n1;i++){
                int r=q.front().first , c=q.front().second;
                q.pop();
                if(r+1<m && grid[r+1][c]=='1' && !visited[r+1][c]){
                    visited[r+1][c]=true;
                    q.push({r+1,c});
                }
                if(r-1>=0 && grid[r-1][c]=='1' && !visited[r-1][c]){
                    visited[r-1][c]=true;
                    q.push({r-1,c});
                }
                if(c+1<n && grid[r][c+1]=='1' && !visited[r][c+1]){
                    visited[r][c+1]=true;
                    q.push({r,c+1});
                }
                if(c-1>=0 && grid[r][c-1]=='1' && !visited[r][c-1]){
                    visited[r][c-1]=true;
                    q.push({r,c-1});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m=grid.size() , n=grid[0].size() , cnt=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cnt+=1;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};