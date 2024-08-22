// Alien Dictionary

class Solution{
    public:
    void findToPoSortVector(vector<int>&topoSortVector,vector<int>&visited,vector<vector<int>>adjList,int N,int K,int node){
        visited[node] = 1;
        for(auto i:adjList[node]){
            if(!visited[i]){
                findToPoSortVector(topoSortVector,visited,adjList,N,K,i);
            }
        }
        topoSortVector.push_back(node);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>adjList(K);
        for(int i=0;i<(N-1);i++){
            int minLen = min(dict[i].size(),dict[i+1].size());
            for(int j=0;j<minLen;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adjList[dict[i][j]-97].push_back(dict[i+1][j]-97);
                    break;
                }
            }
        }
        vector<int>topoSortVector;
        vector<int>visited(K,0);
        for(int i=0;i<K;i++)
        if(!visited[i])
        findToPoSortVector(topoSortVector,visited,adjList,N,K,i);
        string ans = "";
        reverse(topoSortVector.begin(),topoSortVector.end());
        for(auto i:topoSortVector){
            ans+=char(i+97);
        }
        return ans;
    }
};