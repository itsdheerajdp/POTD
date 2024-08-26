// N-ary Tree Postorder Traversal

class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    void solve(Node* root,vector<int>&ans){
        if(root){
            for(int i=0;i<root->children.size();i++){
                solve(root->children[i],ans);
            }
            ans.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};