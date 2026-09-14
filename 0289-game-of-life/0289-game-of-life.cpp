class Solution {
public:
    int check(int cnt,int i,int j,vector<vector<int>>&board){
        int m=board.size()  , n=board[0].size();
        if(i+1<m && (board[i+1][j]==1 || board[i+1][j]==2)) cnt+=1;
        if(i-1>=0  && (board[i-1][j]==1 || board[i-1][j]==2)) cnt+=1;
        if(j-1>=0 && (board[i][j-1]==1 || board[i][j-1]==2)) cnt+=1;
        if(j+1<n && (board[i][j+1]==1 || board[i][j+1]==2)) cnt+=1;
        if(i+1<m && j+1<n && (board[i+1][j+1]==1 || board[i+1][j+1]==2)) cnt+=1;
        if(i-1>=0 && j-1>=0 && (board[i-1][j-1]==1 || board[i-1][j-1]==2)) cnt+=1;
        if(i+1<m && j-1>=0  && (board[i+1][j-1]==1 || board[i+1][j-1]==2)) cnt+=1;
        if(i-1>=0 && j+1<n && (board[i-1][j+1]==1 || board[i-1][j+1]==2)) cnt+=1; 
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m=board.size() , n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ngh=check(0,i,j,board);
                if((board[i][j]==0 || board[i][j]==3)&& ngh==3) board[i][j]=3;
                else if(board[i][j]==1 || board[i][j]==2){
                    if(ngh<2) board[i][j]=2;
                    else if(ngh==2 || ngh==3) board[i][j]=1;
                    else if(ngh>3) board[i][j]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==3) board[i][j]=1;
            }
        }
    }
};
/**dead-0
live  - 1
live to dead - 2
dead to live - 3**/
