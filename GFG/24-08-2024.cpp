// 0 - 1 Knapsack Problem

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, vector<int>& wt, vector<int>& val,int index,vector<vector<int>>&dp){
        if(W==0 or index>=wt.size())
            return 0;
        if(dp[index][W]!=-1)
            return dp[index][W];
        // include case
        int include = 0;
        if(wt[index]<=W)
            include = val[index]+solve(W-wt[index],wt,val,index+1,dp);
        // exclude case
        int exclude = solve(W,wt,val,index+1,dp);
        return dp[index][W]= max(include,exclude);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(W,wt,val,0,dp);
    }
};  