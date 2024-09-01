// Convert 1D Array Into 2D Array
class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        int index = 0;
        if(m*n!=original.size())
            return {};
        while(m--){
            int tmp = n;
            vector<int>row;
            while(tmp--){
                row.push_back(original[index++]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};