// Count Sub Islands

class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    void func(int i, int j, int n, int m, int& f, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(grid2[i][j]==0) return;
        if(grid2[i][j]==1){
            if(grid1[i][j]==0){
                f=0;
                return;
            }
            grid2[i][j]=0;
        }

        
        func(i+1, j, n, m, f, grid1, grid2);
        func(i-1, j, n, m, f, grid1, grid2);
        func(i, j+1, n, m, f, grid1, grid2);
        func(i, j-1, n, m, f, grid1, grid2);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(), m=grid1[0].size();
        int count=0;    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]==1){
                    int f=1;
                    func(i, j, n, m, f, grid1, grid2);
                    if(f==1) count++;
                }
            }
        }
        return count;
    }
};