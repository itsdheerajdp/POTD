// Most Stones Removed with Same Row or Column

class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    void dfs(vector<vector<int>>& stones,int index,vector<bool>&visited){
        if(index>=stones.size())
            return;
        visited[index] = true;
        for(int i=0;i<stones.size();i++){
            if(!visited[i]){
                // in same row 
                if(stones[index][0]==stones[i][0])
                    dfs(stones,i,visited);
                if(stones[index][1] == stones[i][1])
                    dfs(stones,i,visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int groups = 0;
        int n = stones.size();
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(stones,i,visited);
                groups++;
            }
        }
        return n-groups;
    }
};