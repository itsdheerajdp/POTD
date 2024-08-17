// LeetCode 1937. Maximum Number of Points with Cost
class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    // long long solve(vector<vector<int>>&points,int row,int prevCol,vector<vector<long long>>&dp){
    //     if(row>=points.size())
    //         return 0;
    //     long long num_cols = points[row].size();
    //     if(dp[row][prevCol+1]!=-1)
    //         return dp[row][prevCol+1];
    //     long long ans = INT_MIN;
    //     for(long long i = 0;i<num_cols;i++){
    //         long long negScore = prevCol==-1?0:abs(i-prevCol);
    //         ans = max(ans,points[row][i]-negScore+solve(points,row+1,i,dp));
    //     }
    //     return dp[row][prevCol+1]=ans;
    // }
    long long maxPoints(vector<vector<int>>& points) {
    long long rows = points.size();
    long long cols = points[0].size();
    vector<long long> prevRow(cols, 0);
    for(long long i = 0; i < cols; i++) {
        prevRow[i] = points[0][i];
    }
    vector<long long>left(cols),right(cols);
    for(long long i = 1; i < rows; i++) {
        // getting values for left max and right max arrays
        left[0] = prevRow[0];
        for(long long j =1;j<cols;j++)
            left[j] = max(left[j-1]-1,prevRow[j]);
        right[cols-1] = prevRow[cols-1];
        for(long long j = cols-2;j>=0;j--)
            right[j] = max(right[j+1]-1,prevRow[j]);
        


        for(long long j = 0;j<cols;j++){
            prevRow[j] = points[i][j]+ max(right[j],left[j]);
        }
        
    }
    long long ans = LLONG_MIN;
    for(long long i = 0; i < cols; i++) {
        ans = max(ans, prevRow[i]);
    }
    
    return ans;
}
};