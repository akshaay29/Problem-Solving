class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==1) fresh+=1;
                else if(grid[row][col]==2) q.push({row,col});
            }
        }
        int min=0;
        vector<pair<int,int>>direction;
        direction.push_back({-1,0});
        direction.push_back({1,0});
        direction.push_back({0,-1});
        direction.push_back({0,1});
        while(!q.empty()){
            bool spread=false;
            int n=q.size();
            for(int i=0;i<n;i++){
                int r=q.front().first , c=q.front().second;
                q.pop();
                for(auto dir:direction){
                    int nR=r+dir.first;
                    int nC=c+dir.second;
                    if(nR>=0 && nR<grid.size() && nC>=0 && nC<grid[0].size() && grid[nR][nC]==1){
                        fresh-=1;
                        grid[nR][nC]=2;
                        q.push({nR,nC});
                        spread=true;
                    }
                }
            }
            if(spread) min+=1;
        }
        return (fresh!=0 ? -1:min);
    }
};