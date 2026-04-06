class Solution {
public:
    bool isValid(int row,int col,int n,vector<string>&board){
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q') return false;
        }
        for(int i=0;i<n;i++) if(board[i][col]=='Q') return false;
        for(int i=row , j=col;i>=0 && j<n;i-- , j++) if(board[i][j]=='Q') return false;
        for(int i=row , j=col;i>=0 && j>=0;i-- ,j--) if(board[i][j]=='Q') return false;
        return true;
    }
    void solve(vector<string>&board,vector<vector<string>>&ans,int row,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isValid(row,j,n,board)){
                board[row][j]='Q';
                solve(board,ans,row+1,n);
                board[row][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n+1,string(n,'.'));
        solve(board,ans,0,n);
        return ans.size();
    }
};