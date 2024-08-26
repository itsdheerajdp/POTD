// Wildcard Pattern Matching

class Solution {
  public:
    /*You are required to complete this method*/
    int solve(string pattern,string str,int i,int j,vector<vector<int>>&dp){
        if(i>=pattern.size() and j>=str.size())
            return 1;
        else if(i>=pattern.size())
            return 0;
        else if(j>=str.size()){
            for(int k=i;k<pattern.size();k++){
                if(pattern[k]!='*')
                    return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int include = 0;
        if(pattern[i]==str[j] or pattern[i]=='?')
            include = solve(pattern,str,i+1,j+1,dp);
        else if(pattern[i]=='*'){
            
            //  if i'm using * as space 
            int space = solve(pattern,str,i+1,j,dp);
            // if i'm using * as some current character
            int character = solve(pattern,str,i,j+1,dp);
            include =  space or character;
        }
    
        
        return dp[i][j]= include;
    }
    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(pattern,str,0,0,dp);
    }
};