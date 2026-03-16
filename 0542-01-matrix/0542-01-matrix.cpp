class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>>distance(mat.size(),vector<int>(mat[0].size(),-1));
        vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        for(int row=0;row<mat.size();row++){
            for(int col=0;col<mat[0].size();col++){
                if(mat[row][col]==0) {
                    q.push({row,col});
                    distance[row][col]=0;
                } 
            }
        }
        while(!q.empty()){
            pair front=q.front();
            q.pop();
            for(auto dir:direction){
                int r=front.first , c=front.second;
                int nR=r+dir.first , nC=c+dir.second;
                if(nR>=0 && nC>=0 && nR<mat.size() && nC<mat[0].size() && distance[nR][nC]==-1){
                    distance[nR][nC]=distance[r][c]+1;
                    q.push({nR,nC});
                }
            }
        }
        return distance;
    }
};