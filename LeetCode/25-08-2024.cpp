// Binary Tree Postorder Traversal

class Solution {
public:
    void solve(TreeNode* root,vector<int>&ans){
        if(root){
            solve(root->left,ans);
            solve(root->right,ans);
            ans.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};