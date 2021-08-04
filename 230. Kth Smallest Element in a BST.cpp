/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> vals;
    void inorder_traversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder_traversal(root->left);
        vals.push_back(root->val);
        inorder_traversal(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder_traversal(root);
        if(vals.size()>=k){
            return vals[k-1];
        }
        else{
            return -1;
        }
    }
};
