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
TreeNode* buildTree(vector<int>& preorder,int pstart, int psize, vector<int>& inorder, int istart,int isize) {
        //Two things 1) Preorder and inorder
        if(preorder.size()==0 || psize<=0 ||pstart>=preorder.size()){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[pstart]);
        int x=istart;
        int i=0;
        while(inorder[x]!=root->val){
            x++;
            i++;
        }
        root->left=buildTree(preorder,pstart+1,i,inorder,istart,i);
        root->right=buildTree(preorder,pstart+1+i,psize-i-1,inorder,istart+i+1,psize-i-1);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};
