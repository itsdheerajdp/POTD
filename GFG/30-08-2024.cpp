// N-Queen Problem

class Solution{
public:
    bool isSafe(vector<vector<int>>board,int row,int col){
        int n = board.size();
        // checking same column
        for(int i=0;i<row;i++){
            if(board[i][col]==1)
                return false;
        }
        
        // checking same row
        for(int i=0;i<col;i++){
            if(board[row][i])
                return false;
        }
        
        // diagonally backward 
        int i = row-1;int j = col-1;
        while(i>=0 and j>=0){
            if(board[i][j])
                return false;
            i-=1;
            j-=1;
        }
        
        // diagonally forward
        i = row-1;
        j = col+1;
        while(i>=0 and j<n){
            if(board[i][j])
                return false;
            i-=1;
            j+=1;
        }
        
        return true;
    }
    void solve(int n,vector<vector<int>>board,int row,vector<vector<int>>&ans){
       if(row>=n){
           vector<int>tmp;
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(board[i][j]){
                       tmp.push_back(j+1);
                   }
               }
           }
           ans.push_back(tmp);
           return;
       }
       for(int i=0;i<n;i++){
           if(isSafe(board,row,i)){
               board[row][i] = 1;
               solve(n,board,row+1,ans);
               board[row][i] = 0;
           }
       }
    
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        solve(n,board,0,ans);
        return ans;
    }
};