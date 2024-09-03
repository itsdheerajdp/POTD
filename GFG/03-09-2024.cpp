// Minimum number of deletions and insertions

class Solution{
		

	public:
	int lcs(string str,string target,int i,int j,vector<vector<int>>&dp){
	   if(i>=str.size() or j>=target.size()){
	       return 0;
	   }
	   if(dp[i][j]!=-1)
	        return dp[i][j];
	   if(str[i]==target[j]){
	       return dp[i][j]=1+lcs(str,target,i+1,j+1,dp);
	   }else{
	       return dp[i][j]=max(lcs(str,target,i+1,j,dp),lcs(str,target,i,j+1,dp));
	   }
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();int m = str2.size();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	    int longestCommonSubsequence =  lcs(str1,str2,0,0,dp);
	    int difference = str1.size()-longestCommonSubsequence;
	    int insert = str2.size() - longestCommonSubsequence;
	    return difference + insert;
	} 
};